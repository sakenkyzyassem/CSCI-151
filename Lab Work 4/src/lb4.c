#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {

	setvbuf (stdout, NULL, _IONBF, 0);

/*
 * Task1
 */
	char letter;
	char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
	int i;
	int num[26];

	printf("Write something: ");

	for(i =0; i<26; i++){
		num[i] = 0;}

	do {
		letter = getchar();

		i=0;
		while(alphabet[i] != letter){
			i++;
		}
		num[i]++;
	}while(letter != '\n');

	for(i=0; i<26; i++){
	if(num[i]>0){
		printf("You entered %c letter %i times\n", alphabet[i], num[i]);}
	}


/*
 * Task 2
 */
		puts("");

		printf("Please enter (s) or (r): ");
		char ch = getchar();

		if (ch == 'r') {
			printf("you called the rand() function, it has generated the number %i", rand());}

		else if (ch == 's') {
			int seed = time(NULL) ;
			srand( seed );
			printf("You called the srand() function, it has generated the number %i", rand());}
/*
 * Challenging question
 */
		puts("");

		int j, a;
		char option[20];
		int seed = time ( NULL );

		srand( seed );

		seed = seed % 101;

		printf("\nWelcome to the guessing game!\n");
		letter = getchar();
		do {
			printf("Choose an option: \n('s' to start a new game; 'q' to quit the game): ");
			scanf("%s", option);

			if (option[0] == 's') {
				printf("The secret number is between 0 and %i. Guess: ", 100);
				for(j = 1; ;j++ ) {
						scanf("%i", &a);

						if (a > seed) {
							printf("Try to enter lower number: ");}
						else if (a < seed){
							printf("Try to enter higher number: ");}
						else if (a == seed){
							printf("Awesome! You are right\n");
						break;}
				}
			}
			}while(option[0] != 'q');

		printf("Thank you! Bye!");

		return 0;
	}

