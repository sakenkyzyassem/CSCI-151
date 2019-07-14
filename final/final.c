#include <stdio.h>
#include <math.h>

/*#define TEST
#ifdef RELEASE
 #define DEBUG
 #define SAFETY "low"
#elif defined(TEST)
 #define FLAG 2
 #define SAFETY "medium"
#else
 #define SAFETY "high"
#endif
#ifdef FLAG
 #define LEVEL 10
#else
 #define FLAG 4
 #define LEVEL 20
#endif
int main () {
 printf("Safety:%s Flag:%i Level:%i", SAFETY, FLAG, LEVEL);
 return 0;
}*/
void swap(int *i, int *j){
	int temp = *i;
	*i = *j;
	*j = temp;
}

void bubbleSort(int x[], int size){
	int j, swapped=1;

	while(swapped == 1){
		swapped =0;
		for(j=0; j<size-1; j++){
			if(x[j]>x[j+1]){
				swap(&x[j], &x[j+1]);
				swapped = 1;
			}
		}
	}
}

int partition(int x[], int s, int e){
	int pivot = s, up = s, down = e;

	while(up<down){
		while(x[pivot]>=x[up] && up<e){
			up++;}
		while(x[pivot]<=x[down] && down>s){
			down--;}
		if(up<down)
			swap(&x[up], &x[down]);
	}
	swap(&x[pivot], &x[down]);

	return down;
}

void quickSort(int x[], int s, int e){
	int pivot;

	if(s<e){
		pivot = partition(x, s, e);
		quickSort(x, s, pivot-1);
		quickSort(x, pivot+1, e);
	}
}

void printing(int x[], int size){

int i;

printf("{");

for(i=0; i<size-1; i++){

printf("%i ", x[i]);
    }

printf("%i}\n", x[i]);
}


int main(void)
{

int x[20] = {-5, 7, 3, 1, 8, 20, 0, 6, 12, -13, 5, 1, 25, 65, -13, 45, 98, -48, 0, 6};

printing(x, 20);

//selectionSort(x, 20);

//insertionSort(x, 20);

//bubbleSort(x, 20);

quickSort(x, 0, 19);

printing(x, 20);

    return 0;
}
