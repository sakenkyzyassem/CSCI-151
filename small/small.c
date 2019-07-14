#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readFile2(char filename[], char *ArrayPtr[]){
    FILE *infile;
    infile = fopen(filename, "r");
    int i=0;

    while(fgets(ArrayPtr[i], 50, infile) != NULL){
        ArrayPtr[i][strlen(ArrayPtr[i])-1] = '\0';
        i++;}

    fclose(infile);
}

int main(){
    setvbuf(stdout, NULL, _IONBF, 0);

    char *arr[11]; int i;
    for(i=0; i<11; i++){
        arr[i] = (char*)malloc(50*sizeof(char));}

    readFile2("Test.txt", arr);

    for(i=0; i<11; i++)
       printf("%s\n", arr[i]);

    for(i=0; i<11; i++)
        free(arr[i]);
    return 0;
}
