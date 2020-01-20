/*
### Task 1

 - Find the maximum number of an array

### Task 2

 - Print an array prettily e.g "1, 2, 3, 4"
*/

#include <stdio.h>

void maxFunc(int n, int val[]){
	int i, max = val[0];

	for(i=0; i<n; i++){
		if (val[i]>=max){
			max = val[i];
		}
	}
	printf("%i", max);
}

void prettyFunc(int m, int array[]){
	int i;

	for(i=0; i< m-1; i++){
		printf("%i,", array[i]);
	}
	printf("%i", array[i]);
}

int WinMain (){

	//Task 1
	int arr[5] ={25, 68, 12, 88, 49};

	maxFunc(5, arr);

	//Task 2

	puts("");
	int prrtArray[5] = {1, 2, 3, 4, 5};

	prettyFunc(5, prrtArray);


	return 0;
}

