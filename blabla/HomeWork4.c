#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
	char strData[50];
	struct _Node *next;
} Node;

void printLinkedlist(Node *head) {
	if (head != NULL) {
	printf("%s", head->strData);
	printLinkedlist(head->next);
 }
}
void freeLinkedlist(Node *head) {
	if (head == NULL) {
		freeLinkedlist(head->next);
		free(head);
 }
}
void appendNode(Node **oLinkedList, char outputLine[]){
	int i;
	Node *last = NULL, *newNode;
	newNode = (Node*)malloc(50*sizeof(Node));
    newNode->next = NULL;

    for (i=0; i<strlen(outputLine); i++){
    newNode->strData[i]= outputLine[i];
    }

    printf("%s", newNode->strData);

    if (*oLinkedList == NULL){
            printf("aaa");
    	*oLinkedList = newNode;
    printf("bdd");
    } else {
        printf("f");
        last = *oLinkedList;
        printf("f");
    	 while(last->next != NULL) {
    	        last = last->next; }
printf("s");
        last->next = newNode;
    }
    printf("\nOOOO");
    }
void writeFile2(char fileName[], char ssData[], Node **oLinkedList) {
	FILE *file;
	Node *pointer = *oLinkedList;
	file = fopen(fileName, "a");
	fprintf(file, "%s", ssData);
	fprintf(file, "%c", '\n');
	while (pointer != NULL)
		  {
			fprintf(file, "%s", pointer->strData);
		    pointer = pointer->next;
		  }
	fprintf(file, "%c", '\n');
	fclose(file);
}
int isPalindrome(char str[]) {
	int i, j = 0;
	i = strlen(str) - 1;
	do{
		if (str[j++] != str[i--]) {
			return 1;
		}
	} while (i > j) ;
	return 0;
}
char *getPalindrome(char str[]){
	int i;
	i = isPalindrome(str);
	if (i == 0) {
		return "Is_Palindrome";
	} else {
		return "Not_Palindrome";
	}
}

int howManySubstrings(char subStr[], char str[]){
	int subsize, strsize;
	int i;

	subsize = strlen(subStr);
	strsize = strlen(str);
	int limit = strsize - subsize;
	int count = 0;
	char strslice[subsize];
	for( i = 0; i < limit; i++){
		strncpy(strslice, str + i, subsize);
		if (strcmp(subStr, strslice) == 0) {
			count++;
        i=i+subsize-1;
		}
	}
		return count;
}

void checkSubstringPalindrome2(char ssData[], char *iStringData[], Node **oLinkedList, int nrlOfileLines) {
	int j, n, number;
	char oStringData[50][50];
	char *ch= (char*)malloc(20*sizeof(char));
	for(j=0; j < nrlOfileLines; j++){
		number = howManySubstrings(ssData, iStringData[j]);
			for(n=0; *(ch-1) != '\0'; n++){
	                *ch = *(getPalindrome(iStringData[j])+n);
	                ch++;
	        }
	        *ch = '\0';
	        ch=ch-n;
	        snprintf(oStringData[j], 50, "%s%c%i%c%s%c", iStringData[j], '\t', number, '\t', ch, '\n');
	        appendNode(oLinkedList, oStringData[j]);
printf("out of append");
	}

	free(ch);
}

void readFile2(char filename[], char *ArrayPtr[]) {
	int i, j, n=0;
	char array[50][50];
	FILE*file;
	file = fopen(filename, "r");

	for (i = 0; fgets(array[i], 50, file) != NULL; i++, n++) {
		j = strlen(array[i]);
		array[i][j - 1] = '\0';
	}

	for (i = 0; i < n; i++) {
		*(ArrayPtr + i) = array[i];
	}
	fclose(file);
}

int countFileLines(char filename[]) {
	int i;
	char infile[50];
	FILE*file;
	file = fopen(filename, "r");
	for (i = 0; fgets(infile, 50, file) != NULL; i++) {
	}
	fclose(file);
	return i;
}

void openWriteFile(char str[]){
	FILE *file;
	file = fopen(str, "w");

	if(file == NULL){
		printf("Error");
		exit (1);
	}
}
 // 1. the main function, which calls all others
int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	int n, m, l, i;
 // 2. countFileLines - counts the number of lines in both files
	i = countFileLines("iStrings.txt");
	char *array1[i], array[50][i];
	for(n=0;n<i;n++){
        array1[n] = (char*)malloc(sizeof(char)*50);}
	readFile2("iStrings.txt", array1);
 //3. readFile2 - saves all data, which located in files into pointers
	int j;
	j = countFileLines("subStrings.txt");
	char *array2[j];
	readFile2("subStrings.txt", array2);
 //this function opens oStrings.txt file in order to delete all information, which was there before
	openWriteFile("oStrings.txt");
	FILE *file;
	file = fopen("subStrings.txt", "r");
 //this loop reads and stores data located in subStrings in array
	for (m = 0; fgets(array[m], 50, file) != NULL; m++) {
		l=strlen(array[m]);
	    array[m][l-1]='\0';
		}
 //this loop calls functions checkSubstringPalindrome2, writeFile2, printLinkedlist and freeLinkedlist for every substring
    Node *temp = NULL;
    Node **oLinkedList1=NULL;

	for (n=0; n<j; n++){
		checkSubstringPalindrome2(array2[n], array1, oLinkedList1, i);
		printf("checked");
		writeFile2("oStrings.txt", array2[n], oLinkedList1);
	}

	printLinkedlist(temp);
    freeLinkedlist(temp);
	return 0;
}
/*
 * https://www.geeksforgeeks.org/c-program-check-given-string-palindrome/
 *
 * Reffered code 1:
 * int i, j = 0;
	i = strlen(str) - 1;
	do{
		if (str[j++] != str[i--]) {
			return 1;
		}
	} while (i > j) ;
	return 0;
 *
 */
