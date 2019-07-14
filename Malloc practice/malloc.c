#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int rain;
	double temp, wind;
}class;

int rainfall(class *arr){
	int i, count = 0;

	for(i=0; i<12; i++, arr++){
	count = count + arr->rain;
	}

	return count;
}

double lowest_avg_temp(class *arr){
	double min= arr->temp;
	int i;

	for(i=0; i<12; i++, arr++){
		if(arr->temp <= min){
			min = arr->temp;
		}
		else{
			continue;}
	}

	return min;
}

double avg_wind(class *arr){
	double avg= 0; int i=0;

	while(i != 12){
		avg = avg + arr->wind;
		arr++; i++;
	}

	return avg = avg/12;
}

void print(class *arr){
	printf("Rain     Avg.Temp     Avg.Wind\n");
	int i;
	for(i=0; i<12; i++, arr++){
		printf(" %2i       %4.1lf          %3.1lf\n", arr->rain, arr->temp, arr->wind);
	}
}

double lowestAvgTemp(class arr[]){
	return 1.2;
}
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);

	int i, n_rain; double temp, wind;
	class *year = (class*)malloc(12*sizeof(class));

	FILE *infile;
	infile = fopen("weather.txt", "r");

	for(i=0; i<12; i++){
		fscanf(infile, "%i %lf %lf", &year->rain, &year->temp, &year->wind);
		//printf("%i %lf %lf\n", year->rain, year->temp, year->wind);
		year++;
	}
	year = year -12;

	n_rain = rainfall(year);
	printf("The total rainfall for the entire year: %i\n", n_rain);
	temp = lowest_avg_temp(year);
	printf("The lowest average temperature is: %lf\n", temp);
	wind = avg_wind(year);
	printf("Average of averages of wind is: %lf\n", wind);
	puts("");
	print(year);

	free(year);
	return 0;
}
