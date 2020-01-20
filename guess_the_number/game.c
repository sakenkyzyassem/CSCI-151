#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	setvbuf(stdout, NULL, _IONBF, 0);

	char variant[4] = {'s', 'n', 'q', '\0'};
	int i = 0;
	int integer;
	int loop, range = 9999;
	double count = 0, tot_loop = 0;
	int correct;

	printf ("WELCOME to the Guessing game!\n");

	do {
//Random number
		int seed = time (NULL);
		srand( seed );
		seed =seed % (range +1);

		printf("MENU:(s) to start a game,(n) to set a new range,(q) to quit:\n");
		scanf("%s", variant);
		switch (variant[i]) {
// FOR NEW GAME COMMAND
		case 's':
		correct = 0;
		count++;
		printf("The secret number is BETWEEN 0 AND %i. Try to guess:\n", range);
//loop for guessing
		for(loop = 1;correct == 0 ;loop++) {
			scanf("%i", &integer);
				if (integer == seed){
					printf("Awesome! You TOOK %i guesses!\n", loop);
					correct = 1;}
				else if (integer > seed) {
					printf("Too HIGH. Try again:\n");}
				else if (integer < seed){
					printf("Too LOW. Try again:\n");}
		}
	tot_loop = tot_loop + loop - 1;
	break;
// FOR NEW RANGE COMMAND
		case 'n':
		printf("Enter a new MAXIMUM:\n");
		scanf("%i", &range);
		break;
// FOR QUITTING COMMAND
		case 'q' :
		break;
// DEFAULT
		default:
		printf("UNRECOGNIZED command, try entering again...\n");}

	}while (variant[i] != 'q');

	if (tot_loop/count > 0){
	printf("Thank you for playing my game! Your guess count AVERAGE %.1f", tot_loop/count);}
	else {
	printf("Thank you for playing my game! Your guess count AVERAGE 0.0");	}

	return 0;
}

