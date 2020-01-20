#include <stdio.h>
#include <stdlib.h>

typedef struct _class{
	int rain;
	double temp, wind;
	struct _class *link;
}class;

typedef struct _alphabet{
	char ch;
	struct _alphabet *link;
}alphabet;

int rainfall(class *arr){
	int count = 0;

	while(arr != NULL){
	count = count + arr->rain;
	arr = arr->link;
	}

	return count;
}

double lowest_avg_temp(class *arr){
	double min= arr->temp;

	while(arr != NULL){
		if(arr->temp <= min){
			min = arr->temp;}

		arr= arr->link;
	}

	return min;
}

double avg_wind(class *arr){
	double avg= 0;

	while(arr != NULL){
		avg = avg + arr->wind;
		arr = arr->link;
	}

	return avg = avg/12;
}

void print(class *arr){
	printf("Rain     Avg.Temp     Avg.Wind\n");

	while(arr != NULL){
		printf(" %2i       %4.1lf          %3.1lf\n", arr->rain, arr->temp, arr->wind);
		arr = arr->link;
	}
}

void freeAll(class *c){
	if(c!= NULL){
		freeAll(c->link);
		free(c);
	}
}

void printList(alphabet *al){

	while(al != NULL){
		printf("%c ", al->ch);
		al = al->link;
	}
}

void reversePrint(alphabet *al){
	if(al != NULL){
		reversePrint(al->link);
		printf("%c ", al->ch);
	}
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
/*
	int i=0, n_rain; double temp, wind;
	class *first = NULL;
	class *prev = NULL;

	FILE *infile;
	infile = fopen("weather.txt", "r");

	while(i<12){
		class *new = (class*)malloc(sizeof(class));
		new->link = NULL;

		fscanf(infile, "%i %lf %lf", &new->rain, &new->temp, &new->wind);
		if(i == 0){
			first = new;}
		else{
			prev->link = new;}

		prev = new;
		i++;
	}

	n_rain = rainfall(first);
	printf("The total rainfall for the entire year: %i\n", n_rain);
	temp = lowest_avg_temp(first);
	printf("The lowest average temperature is: %lf\n", temp);
	wind = avg_wind(first);
	printf("Average of averages of wind is: %lf\n", wind);
	puts("");
	print(first);

	freeAll(first);
*/
//Task 1

	alphabet *a= NULL;
	alphabet *last = NULL;
	int i=0;

	while(i<26){
		alphabet *new = (alphabet*)malloc(sizeof(alphabet));
		new->link = NULL;

		new->ch = 'a'+i;

		if(i == 0)
			a = new;
		else
			last->link = new;

		last = new;
		i++;
	}

	printList(a);
	puts("");
	reversePrint(a);

	return 0;
}
