#include <stdio.h>
#include <stdlib.h>

int WinMain() {

	setvbuf (stdout, NULL, _IONBF, 0);

/*	FILE *input;
	FILE *written;

	input = fopen("textedfile.txt", "r");
	written = fopen("writtenfile.txt", "w");

	if (input == NULL || written == NULL){
		printf("There is a problem opening a file.");
		return 1;
	}
	printf("File opened successfully");

	char text[81];

	do{
		fscanf(input, "%s", text);
		fprintf(written, "The text is: %s \n", text);

		printf("The text is: %s \n", text);
	}while (!feof(input));

	fclose(input);
	fclose(written);*/

/*Write a program that copies the contents of an input file,
 * and writes them to another file.
 * The input and output file names should be provided by the user via the
 * console at the beginning of the program.
 * Hint: Copy the files, character by character.
 */

	char infile[81], outfile[81];
	FILE *inputfile, *outputfile;
	char num;

	printf("Write the name of a file to be copied: ");
	scanf("%s", infile);
	printf("Write the name of output file: ");
	scanf("%s", outfile);

	inputfile = fopen(infile, "r");
	outputfile = fopen (outfile, "w");

	if (inputfile == NULL){
		printf("Problem opening %s file", infile);
		return 1;	}

	if (outputfile == NULL) {
		printf("Problem copying to the file %s", outfile);
		return 2;
	}

	do{
		num = getc(inputfile);

		putc(num, outputfile);

		printf("%c", num);

	}while(!feof(inputfile));

/*
 * Create a program that substitutes the words found in the file values.txt in for the
 * ‘$’ characters found in story.txt, and prints the result out to the console window
 */
/*	FILE *value, *story;

	value = fopen("values.txt", "r");
	story = fopen("story.txt", "a+");

	if (value == NULL || story == NULL){
		printf("Error opening files");
		return 1;
	}

	printf("Files successfully opened\n");

	char text[81], val[20];
	int i;

	for(i=0; !feof(story); i++){
		 fscanf(story, "%s", text);
		 	 	if (text[i] == '$'){
		 	 			fscanf(value, "%s\n", val);
		 	 			fprintf(story, "%s", val);
		 	 			printf("%s ", val);
		 	 		 }
		 	 	else{
		 	 		printf("%s ", text);}
	}

	fclose(value);
	fclose(story);*/

	return 0;
}
