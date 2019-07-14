#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 50

typedef struct _Node{
char strData[50];
struct _Node *next;
}Node;

_Bool fileOpening_r(char filename[]);

_Bool fileOpening_w(char filename[]);

int countFileLines(char filename[]);

int isPalindrome(char str[]);

char *getPalindrome(char str[]);

int howManySubstrings(char subStr[], char str[]);

void writeFile2(char fileName[], char ssData[], Node **oLinkedList){
    FILE *infile;
    infile = fopen(fileName, "w");

    fputs(ssData, infile);
    fputc('\n', infile);

    while((*oLinkedList) != NULL){
        fputs((*oLinkedList)->strData, infile);
        (*oLinkedList) = (*oLinkedList)->next;
    }
    fputc('\n', infile);

    fclose(infile);
}

void freeLinkedlist(Node *head){
    Node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);}
}

void printLinkedlist(Node *head){
    while(head != NULL){
        printf("%s", head->strData);
        head = head->next;
    }
}

void appendNode(Node **oLinkedList, char outputLine[]){
    printf("<<In appendNode>>\n");

    Node *new = (Node*)malloc(SIZE*sizeof(char));
    printf("!!!\n");
    new->next = NULL;

    memcpy(new->strData, outputLine, sizeof(char)*(strlen(outputLine)));
    new->strData[strlen(outputLine)] = '\0';
    (*oLinkedList)->next = new;
    (*oLinkedList) = new;
    printf("New string: %s, copied: %s\n", new->strData, (*oLinkedList)->strData);

}

void appendAll(char iStringData[], Node **oLinkedList, char palin_arr[], int n){
    char ch = n + '0';
    char tabArr[2] = {'\t', '\0'}, new_lineArr[2] = {'\n', '\0'}, num[2] ={ch, '\0'}, new_arr[50];

    strcpy(new_arr, iStringData);
    strcat(new_arr, tabArr);
    strcat(new_arr, num);
    strcat(new_arr, tabArr);
    strcat(new_arr, palin_arr);
    strcat(new_arr, new_lineArr);
    appendNode(oLinkedList, new_arr);
    printf("Array: %s, copied: %s", new_arr, (*oLinkedList)->strData);
}

void checkSubstringPalindrome2(char ssData[], char *iStringData[], Node **oLinkedList, int nrIOfileLines){
    int i, num, j;
    char pal[20];

    for(i = 0; i<nrIOfileLines; i++){
        printf("<%i>\n", i);
        num = howManySubstrings(ssData, iStringData[i]);
        printf("For sub: %s, in %s num: %i\n", ssData, iStringData[i], num);
        for(j=0; *(getPalindrome(iStringData[i])+j) != '\0'; j++){
            pal[j] = *(getPalindrome(iStringData[i])+ j);}
        pal[j] = '\0';
        printf("Palindrome: %s\n", pal);
        appendAll(iStringData[i], oLinkedList, pal, num);
        //printf("i = %i, %s>>", i, (*oLinkedList));

    }
    printf("End");
} //new


/*
○ For each string line,
○ This function calls howManySubstrings() to check if there are how many substrings in each line
○ This function calls getPalindrome()
○ Write each output line to the oLinkedList linked list using the output format by calling
appendNode() for each line
(i.e., Original_data_without_leading_or_trailing_whitespace + “\t” + str(count) + “\t” +
is_or_not_Palindrome + “\n” )
*/

void readFile2(char filename[], char *ArrayPtr[]){
    FILE *infile;
    infile = fopen(filename, "r");
    int i=0;

    while(fgets(ArrayPtr[i], 50, infile) != NULL){
        ArrayPtr[i][strlen(ArrayPtr[i])-1] = '\0';
        i++;}

    fclose(infile);
}

int main(void){
    setvbuf(stdout, NULL, _IONBF, 0);

    int i_b, s_b, o_b;
    i_b = fileOpening_r("iStrings.txt");
    s_b = fileOpening_r("subStrings.txt");
    o_b = fileOpening_w("oStrings.txt");

    if(i_b==0 || s_b == 0 || o_b == 0){
        return 1;}

    int i, i_size, sub_size, o_size;
    i_size = countFileLines("iStrings.txt");
    sub_size = countFileLines("subStrings.txt");
    o_size = sub_size*(i_size + 2) +1;

    char *iArr[i_size], *subArr[sub_size];
    for(i=0; i<i_size; i++){
        iArr[i] = (char*)malloc(SIZE*sizeof(char));}
    for(i=0; i<sub_size; i++){
        subArr[i] = (char*)malloc(SIZE*sizeof(char));}

    Node *head = NULL;
    Node *prev = NULL;
    Node **last = (Node**)malloc(o_size*sizeof(Node*));

    readFile2("iStrings.txt", iArr);
    readFile2("subStrings.txt", subArr);

    for(i=0; i<sub_size; i++){
        *last = (Node*)malloc(SIZE*sizeof(Node));
        (*last)->next = NULL;
        checkSubstringPalindrome2(subArr[i], iArr, last, i_size);
        printf("Y");
        writeFile2("oStrings.txt", subArr[i], last);

        if(i==0){
            head = (*last);}
        else{
            prev->next = (*last);}

        prev = (*last);
    }

    printLinkedlist(head);
    freeLinkedlist(head);
return 0;
}

_Bool fileOpening_r(char filename[]){
    FILE *readfile;
    readfile = fopen(filename, "r");

    if(readfile == NULL){
        printf("Error reading %s\n", filename);
        fclose(readfile);
        return 0;}
    else{
        fclose(readfile);
        return 1;}
}

_Bool fileOpening_w(char filename[]){
    FILE *writtenfile;
    writtenfile = fopen(filename, "w"); //set it writing so that at first opening the file it empties it

    if(writtenfile == NULL){
        printf("Error reading %s\n", filename);
        fclose(writtenfile);
        return 0;}
    else{
        fclose(writtenfile);
        return 1;}
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
			n++;}
	    ch[len] = '\0';

	    if(strcmp(ch, subStr) == 0){
			num++;   			//if subStrings are identical number increments
			i=i+len-1;}			//to make sure substrings don't overlap iteration int skips the chars of the subString compared
	}

	return num;
}
