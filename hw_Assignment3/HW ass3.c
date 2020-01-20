#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int size, err;
}string;

void fileOpening_r(char filename[], int *k){
    FILE *readfile;
    readfile = fopen(filename, "r");

    if(readfile == NULL){
        printf("Error reading %s\n", filename);
        *k = 0;}
    else{
        *k = 1;}

    fclose(readfile);
}

void fileOpening_w(char filename[], int *k){
    FILE *writtenfile;
    writtenfile = fopen(filename, "w"); //set it writing so that at first opening the file it empties it

    if(writtenfile == NULL){
        printf("Error reading %s\n", filename);
        *k = 0;}
    else{
        *k = 1;}

    fclose(writtenfile);
}

void readFile(char filename[], char twoDimArr[][50]){
    int i=0;
    FILE *infile;
    infile = fopen(filename, "r");

    while(fgets(twoDimArr[i], 50, infile) != NULL){ //saves string from every line to 2d array
    	twoDimArr[i][strlen(twoDimArr[i])-1] ='\0'; //as fgets function saves string with '\n' char, I need to remove it
        i++;
    }

    fclose(infile);
}

int countFileLines(char filename[]){
    FILE *infile;
    infile = fopen(filename, "r");
    int line=0;
    char ch[50];

    while(fgets(ch, 50, infile) != NULL){
        line++;}

    fclose(infile);
    return line;
}

int isPalindrome(char str[]){
	int len = strlen(str), i, k=0;
	char str1[len];

	for(i = len-1; i>=0; i--, k++){
		str1[k]=str[i];} //changes characters of a string and saves them in str1
	str1[len] = '\0';

	if(strcmp(str, str1) == 0)
		return 1;
	else
		return 0;
}

char *getPalindrome(char str[]){
	int i;
	i = isPalindrome(str);

	if (i == 1){
		return "Is_Palindrome";}
	else{
		return "Not_Palindrome";}

}

int howManySubstrings(char subStr[], char str[]){
	int i, j, len, num=0, n;
	char ch[50];
	len = strlen(subStr);

	for(i=0; str[i+len-1] != '\0'; i++){ //iterates till the size of substring
								//for ex. subString is 'ana' (length 3) and string is Blablabam
						//iteration is done only 7 times, because after bam substring of the same size cannot be formed
		for(j=0, n = i; j<len; j++){	//this for loop makes a substring of the same size to compare with subStr
			ch[j] = str[n];
			n++;
		}
	    ch[len] = '\0';

	    if(strcmp(ch, subStr) == 0){
			num++;   			//if subStrings are identical number increments

	    }			//to make sure substrings don't overlap iteration int skips the chars of the subString compared
	}

	return num;
}


void checkSubstringPalindrome(char subStr[], char iStringData[][50], char oStringData[][50], int nrIOfileLines){
	int i, u=0, subN;
	char pal_arr[20], tabArr[2] = {'\t', '\0'}, new_lineArr[2] = {'\n', '\0'};

	for(i=0; i<nrIOfileLines; i++){

        for(u=0; *(getPalindrome(iStringData[i])+u) != '\0'; u++){
            pal_arr[u] = *(getPalindrome(iStringData[i])+ u);}
        pal_arr[u] = '\0';									//saves the returning char* from getPalindrome to an array

        strcpy(oStringData[i], iStringData[i]); //copies string
        strcat(oStringData[i], tabArr);			//puts '\t' character

        subN = howManySubstrings(subStr, iStringData[i]);  //takes the number of subStrings
        snprintf(oStringData[i], sizeof oStringData[i], "%s%i", oStringData[i], subN); //adds the number of subStrings

        strcat(oStringData[i], tabArr);   //adds '\t' character
        strcat(oStringData[i], pal_arr);      //adds an array getPalindrome
        strcat(oStringData[i], new_lineArr);  //adds '\n' character
        }
}

void writeFile(char fileName[], char ssData[], char oStringData[][50], int nrIOfileLines){
	FILE *outfile; int i;
	outfile = fopen(fileName, "a");

    fputs(ssData, outfile);   //puts subString
    fputs("\n", outfile);

	for(i=0; i<nrIOfileLines; i++){
		fputs(oStringData[i], outfile);} //prints each string

	fputs("\n", outfile);

	fclose(outfile);
}

int main(){
    setvbuf(stdout, NULL, _IONBF, 0);

    string in, sub, out;
    int i;
    char iStr[] = "iStrings.txt", subStr[] = "subStrings.txt", outStr[] = "oStrings.txt";

    fileOpening_r(iStr, &in.err);
    fileOpening_r(subStr, &sub.err);
    fileOpening_w(outStr, &out.err);
    if(in.err == 0 || sub.err == 0 || out.err == 0){ return 1;}

    in.size = countFileLines(iStr);
    sub.size = countFileLines(subStr);
    out.size = sub.size*(in.size + 2); //size of output array = for each subString -> inString size + new line + and subString itself

    char iArray[in.size][50], subArray[sub.size][50], oArray[out.size][50];

    readFile(subStr, subArray);
    readFile(iStr, iArray);

    for(i=0; i<sub.size; i++){		//iterates for each line of subString file
    	checkSubstringPalindrome(subArray[i], iArray, oArray, in.size);
    	writeFile(outStr, subArray[i], oArray, in.size);}

    return 0;
}

