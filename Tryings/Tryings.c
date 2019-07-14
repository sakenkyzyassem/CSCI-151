#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int isPalindrome(char str[]){
	int len = strlen(str), i, k=0;
	char str1[len];

	for(i = len-1; i>=0; i--, k++){
		str1[k]=str[i];}
	str1[k] = '\0';
	if(strcmp(str, str1) == 0)
		return 1;
	else
		return 0;
}

char *getPalindrome(char str[]){
	int i;
	i = isPalindrome(str);

	if (i == 1){
		return "Is_Palindrome\n";}
    else{
		return "Not_Palindrome\n";}
}

int howManySubstrings(char subStr[], char str[]){
	int i, j, len, num=0, n; char ch[50];
	len = strlen(subStr);

	for(i=0; str[i+len] != '\0'; i++){
		n = i;
		for(j=0;j<len;j++){
			ch[j] = str[n];
			n++;}
	    ch[len] = '\0';
	    if(strcmp(ch, subStr) == 0){
			num++; i=i+len-1;}}
	return num;
}

void checkSubstringPalindrome(char subStr[], char iStringData[][50], char oStringData[][50], int nrIOfileLines){
	int i, u=0, len, subN;
	char arr[20], numArr[5], tabArr[2] = {'\t', '\0'};

	for(i=0; i<nrIOfileLines; i++){
        for(u=0; *(getPalindrome(iStringData[i])+u) != '\0'; u++){
            arr[u] = *(getPalindrome(iStringData[i])+ u);}
        strcpy(oStringData[i], iStringData[i]);
        strcat(oStringData[i], tabArr);
        subN = howManySubstrings(subStr, iStringData[i]);
        snprintf(oStringData[i], sizeof oStringData[i], "%s%i", oStringData[i], subN);
        strcat(oStringData[i], tabArr);
        strcat(oStringData[i], arr);
        }
}

/*
For each string line,
This function calls howManySubstrings() to check if there are how many substrings in each line
This function calls getPalindrome()
Write each output line to oStringData Array using the output format
(i.e., Original_data_without_leading_or_trailing_whitespace + “\t” + str(count) + “\t” +
is_or_not_Palindrome + “\n” )
*/

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);

	char file[3][50], subString[]="sta";
	char data[][50] = {{"Astana"}, {"stats"}, {"Astana Astana"}};
	int n = 3;

    checkSubstringPalindrome(subString, data, file, n);

	return 0;
}
