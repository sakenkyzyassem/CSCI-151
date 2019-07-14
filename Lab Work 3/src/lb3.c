#include <stdio.h>

int WinMain (void) {

	setvbuf (stdout, NULL, _IONBF, 0);
/*
 * Task1
 */
	int a;
	int sum = 0;

	do {
		printf("Please enter a number: ");
		scanf("%i", &a);

		sum = a + sum;

	 } while (sum <= 100);

	 printf("You entered %i, I am stopping the program, because the sum became %i\n", a, sum);

/*
 * Task 2
 */

	 int num;
	 int j = 0;

	 puts("");
	 printf("To proceed to the next task press 0\n");

	 for ( ; ; ) {

	 	printf ("Please enter a number: ");
	 	scanf ("%i", &num);


	 	for (j = 2 ; j < num ; j++) {
	 	    	 if (num%j == 0){
	 	    		 break;}
	 	     }

	 	if (num == 1) {
	 	    		 printf ("1 is not a prime number!\n"); }
	 	else if (num == j) {
	 	    		 printf("It is a prime number!\n");}
	 	if (num == 0){
	 		break;}
	 	}

/*
 * Task 3
 */
	 int min;
	 int max;
	 int prime;

	 puts("");

	 printf ("Please enter a range: ");
	 scanf ("%i", &min);
	 scanf ("%i", &max);

	 for (prime = min; prime <= max; prime++) {

	 	 	for (j = 2 ; j < prime ; j++) {    //Variable j was introduced in the previous task
	 	 	    	 if (prime%j == 0){
	 	 	    		 break;}
	 	 	     }

	 	 	if (prime == j) {
	 	 	    		 printf("%i ", prime);}

	 	 }

	 return 0;
}


