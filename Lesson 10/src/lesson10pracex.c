#include <stdio.h>

int main(void) {

	setvbuf (stdout, NULL, _IONBF, 0);
/*
 * number of a letters
 */
	/*printf("Write something: ");

	char ch;
	int n=0;

	do {

	ch = getchar();

	if (ch == 'a' || ch == 'A') {
		n = n+1;}

	} while (ch != '\n');

	printf("You entered %i a-s", n);*/

/*
 * uppercase writing
 */
/*	puts("");
	char text;

	printf("Write sth:");
	do{
		text = getchar();
				if (text >=97 && text <= 122) {
					text = text -32;
					printf("%c", text);
				}
				else {
					printf("%c", text);
				}
	}while (text != '\n');*/

/*
 * number of characters
 */
	puts("");
	char text;
	int n = 0;

	printf("Write a sentence: ");

 do{
	 text = getchar();

	 if (text == 32) {
		 if (n != 0){
		 printf("%i\n", n);}
		 else {
			 continue;}
		 n = 0;
	 }
	 else{
		 n++;}

 }while(text != '\n');

 	 printf("%i\nDone.", n-1);

	return 0;
}
