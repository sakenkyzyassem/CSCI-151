#include <stdio.h>

int main() {

	setvbuf (stdout, NULL, _IONBF, 0);

	int num, day, day_num;

	printf ("Write a number between 1 and 366\nTo quit write a number that is not within this range: ");
	scanf("%i", &num);

	if (num>=1 && num<=366) {

	printf ("It is ");

	day = num % 7;

	switch ( day ) {
		case 1 :
		    printf ("Friday, ");
		    break;
		case 2 :
		    printf ("Saturday, ");
		    break;
		case 3 :
			printf ("Sunday, ");
			break;
		case 4 :
			printf ("Monday, ");
			break;
		case 5 :
			printf ("Tuesday, ");
			break;
		case 6 :
			printf ("Wednesday,");
			break;
		case 0 :
			printf ("Thursday, ");
			break;
	}

	if (num>=1 && num<32) {
		day_num = num;
		printf("January %i", day_num);}
	else if (num>=32 && num<=60) {
		day_num = num - 31;
		printf("February %i", day_num);}
	else if (num>=61 && num<=91) {
		day_num = num - 60;
		printf("March %i", day_num);}
	else if (num>=92 && num<=121) {
		day_num = num - 91;
		printf("April %i", day_num);}
	else if (num>=122 && num<=152) {
		day_num = num - 121;
		printf("May %i", day_num);}
	else if (num>=153 && num<=182) {
		day_num = num - 152;
		printf("June %i", day_num);}
	else if (num>=183 && num<=213) {
		day_num = num - 182;
		printf("July %i", day_num);}
	else if (num>=214 && num<=244) {
		day_num = num - 213;
		printf("August %i", day_num);}
	else if (num>=245 && num<=274) {
		day_num = num - 244;
		printf("September %i", day_num);}
	else if (num>=275 && num<=305) {
		day_num = num - 274;
		printf("October %i", day_num);}
	else if (num>=306 && num<=335) {
		day_num = num - 305;
		printf("November %i", day_num);}
	else if (num>=336 && num<=366) {
		day_num = num - 335;
		printf("December %i", day_num);}
	}

	else {
		printf("Error.");}

	return 0;
}
