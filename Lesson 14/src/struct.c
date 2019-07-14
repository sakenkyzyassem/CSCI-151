#include <stdio.h>
#include <stdlib.h>
/*Define a new structure type called student which has members:
		ID (a six digit student ID)
		gender (the character ‘m’ or ‘f’)
		Three separate members that represent the three different components
	of your CSCI 151 grade (doubles between 0.0 and 100.0)
		finalGrade (a double between 0.0 and 100.0)
Then, write some code that declares a single student variable, and prompts the user
to enter in values for the first five fields, and then uses this information
to calculate and set the finalGrade.  At the end, use a printf statement
that prints out the field contents of the student variable*/
typedef struct{
	int id;
	char mORf;
	double a, b, c;
	double final;
}acc;
int main(void){

	setvbuf(stdout, NULL, _IONBF, 0);

	acc per_acc;

	printf("Write your ID number: ");
	scanf("%i", &per_acc.id);
	printf("Write your gender m/f: ");
	scanf(" %c", &per_acc.mORf);
	printf("Write your three CSCI grades: ");
	scanf("%lf", &per_acc.a);
	scanf("%lf", &per_acc.b);
	scanf("%lf", &per_acc.c);

	printf("Your first three grades are: %.2lf, %.2lf, %.2lf", per_acc.a, per_acc.b, per_acc.c);
	printf("\nFinal grade is %.2lf", (per_acc.a+per_acc.b+per_acc.c)/3);
	printf("\nPercentage is: %.2lf", (per_acc.a+per_acc.b+per_acc.c)*100/3/15);

	return 0;
}
