#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct _Node{
char strData[50];
struct _Node *next;
}Node;

int countFileLines(char filename[]);

int isPalindrome(char str[]);

char *getPalindrome(char str[]);

int howManySubstrings(char subStr[], char str[]);

void fileOpening_r(char filename[]){ //checks a file for validity
    FILE *readfile;
    readfile = fopen(filename, "r");

    if(readfile == NULL){
        printf("Error reading %s\n", filename);
        exit (1);}
    else{
        fclose(readfile);}
}

void fileOpening_w(char filename[]){  //checks a file for validity
    FILE *writtenfile;
    writtenfile = fopen(filename, "w");

    if(writtenfile == NULL){
        printf("Error reading %s\n", filename);
        exit (2);}
    else{
        fclose(writtenfile);}
}

void files_checking(){    //checks all files for validity
    fileOpening_r("iStrings.txt");
    fileOpening_r("subStrings.txt");
    fileOpening_w("oStrings.txt");
}

void counting_All_Lines(int *i, int *s, int *o){
    *i = countFileLines("iStrings.txt");
    *s = countFileLines("subStrings.txt");
    *o = *s * (*i + 2) + 1;
}

void readFile2(char filename[], char *ArrayPtr[]){
    FILE *infile;
    infile = fopen(filename, "r");
    int i=0;

    while(fgets(ArrayPtr[i], 50, infile) != NULL){
        ArrayPtr[i][strlen(ArrayPtr[i])-1] = '\0';
        i++;}

    fclose(infile);
}

void appendNode(Node **oLinkedList, char outputLine[]){

    Node *prev = NULL, *new;
    new = (Node*)malloc(MAX_SIZE*sizeof(Node));
    new->next = NULL;

    //copies the content of outputLine
    memcpy(new->strData, outputLine, sizeof(char)*(strlen(outputLine)));
    new->strData[strlen(outputLine)] = '\0';

    if(*oLinkedList == NULL){
        *oLinkedList = new;
    }
    else{//NOTE: I took the process/idea of adding the 'new' Node from the lecture slides
        //in order to not change the head, assign it to temporary Node for future utility
        prev = *oLinkedList;

        //goes till the end of linked list
        while(prev->next != NULL){
            prev = prev->next;
        }
        //adds newly obtained data to the end of the list
        prev->next = new;
    }

}

void appendAll(char iStringData[], Node **oLinkedList, char palin_str[], int n){
    char ch = n + '0';
    char tab[2] = {'\t', '\0'}, new_line[2] = {'\n', '\0'}, num[2] ={ch, '\0'}, new_str[50];

    //writes all strings of one line to the new string
    strcpy(new_str, iStringData);
    strcat(new_str, tab);
    strcat(new_str, num);
    strcat(new_str, tab);
    strcat(new_str, palin_str);
    strcat(new_str, new_line);
    appendNode(oLinkedList, new_str);
}

void checkSubstringPalindrome2(char ssData[], char *iStringData[], Node **oLinkedList, int nrIOfileLines){
    int i, num, j;
    char pal[20];

    for(i = 0; i<nrIOfileLines; i++){
        num = howManySubstrings(ssData, iStringData[i]);

        for(j=0; *(getPalindrome(iStringData[i])+j) != '\0'; j++){
            pal[j] = *(getPalindrome(iStringData[i])+ j);}
        pal[j] = '\0';

        //appends a new string for the output line and calls appendNode function
        appendAll(iStringData[i], oLinkedList, pal, num);
    }
}

void writeFile2(char fileName[], char ssData[], Node **oLinkedList){
    FILE *infile;
    infile = fopen(fileName, "a");
    Node *temp;

    fputs(ssData, infile);
    fputc('\n', infile);

    //writes the string data till the final Node
    for(temp = *oLinkedList; temp != NULL; temp = temp->next){
        fputs(temp->strData, infile);
    }
    fputc('\n', infile);

    fclose(infile);
}

void printLinkedlist(Node *head){
    //Note: algorithm is from lectures
    while(head != NULL){
        printf("%s", head->strData);
        head = head->next;
    }
}

void freeLinkedlist(Node *head){
    Node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);}
    free(head);
}

void free_array(char *Array[], int rows){  //for freeing an array of pointers
    int i;

    for(i=0; i<rows; i++){
        free(Array[i]);
    }
}

void free_All(Node *head, char *arr1[], int size1, char *arr2[], int size2){ //frees Node and each arrays of pointers
    freeLinkedlist(head);
    free_array(arr1, size1);
    free_array(arr2, size2);
}

int main(void){
    setvbuf(stdout, NULL, _IONBF, 0);

    int i, count;
    files_checking(); //checks files for validity

    int i_size, sub_size, o_size;
    //counts lines of files and returns their value to the addresses
    counting_All_Lines(&i_size, &sub_size, &o_size);

    char *iArr[i_size], *subArr[sub_size];
    for(i=0; i<i_size; i++){
        iArr[i] = (char*)malloc(MAX_SIZE*sizeof(char));}  //dynamically allocates memory for each lines of
    for(i=0; i<sub_size; i++){                            //arrays of pointers
        subArr[i] = (char*)malloc(MAX_SIZE*sizeof(char));}

    readFile2("iStrings.txt", iArr);
    readFile2("subStrings.txt", subArr);

    Node *head = NULL;
    Node *temp = NULL;

    for(i=0; i<sub_size; i++){

        checkSubstringPalindrome2(subArr[i], iArr, &head, i_size);

        //in order to write to the file corresponding lines of strings, temporary Node
        //goes to the according number of line (that is i*i_size) and starts writing for that Node
        temp = head;
        for(count = 0; (count != i*i_size) && i != 0; count++){
            temp = temp->next;
        }

        writeFile2("oStrings.txt", subArr[i], &temp);
    }

    printLinkedlist(head);
    free_All(head, iArr, i_size, subArr, sub_size);
return 0;
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
