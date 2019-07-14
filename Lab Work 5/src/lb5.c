#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {

	setvbuf(stdout, NULL, _IONBF, 0);
/*
 * Task 1
 */
	FILE *file;

	file = fopen ("log.txt", "a");

	char name[20];
	int age, i = 0;

	do {
		printf("Enter your name: ");
		scanf("%s", name);
		if (name[i] == 'q'){
			break;
		}
		else{
			printf("Enter your age: ");
			scanf("%i", &age);
		}
			fprintf(file, "You entered name = %s, age = %i. Successful.\n", name, age);
	}while(name[i] != 'q');

/*
 * Task 2
 */
	puts("");
	int val[12];
	int j, k, max = 0, min = 100;
	double sum = 0;
	srand(time (NULL));

	for(k =0,j =0; j < 12; k++){
		int seed = rand()%101;
		if(seed%2 != 0){
			continue;}
		else {
			val[j] = seed;
			printf("%i\n", val[j]);
			j++;}
	}

	for(j = 0; j<12; j++){
		if (max<val[j]){
			max = val[j];}
		else if (val[j]<max){
			continue;}
	}
	for(j = 0; j<12; j++){
		sum = sum + val[j];
		if (min>val[j]){
			min = val[j];}
		else if (val[j]>min){
			continue;}
	}
	printf("Maximum value is %i\n", max);
	printf("Minimum value is %i\n", min);
	printf("Average is %.2lf\n", sum/12);

/*
 * Task 3
 */

	int matrix[12][12];
	int a, b;

	for (a = 0; a<12; a++){
		for(b = 0; b<12; b++){
			matrix[a][b]=(a+1)*(b+1);}
	}

	for (a = 0; a<12; a++){
		for(b = 0; b<12; b++){
			printf("%2i *%2i = %2i  ", a+1, b+1, matrix[a][b]);}
		printf("\n");}
	return 0;
}
