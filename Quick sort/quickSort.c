#include <stdio.h>

int partition(int x[], int first, int last) {

 int pivot = first;

 int up = first, down = last;
 while (up < down) {

	 while (x[up] <= x[pivot] && up < last) {
		 up++;
	 }
	 while (x[down] > x[pivot]) {
		 down--;
	 }
	 if (up < down) {
		 int temp = x[up];
		 x[up] = x[down];
		 x[down] = temp;
	 }
 }

 int temp2 = x[pivot];
 x[pivot] = x[down];
 x[down] = temp2;

 return down;
}

void quicksort(int x[], int first, int last) {

 if (first < last) {
 int pivIndex = partition(x, first, last);
 quicksort(x, first, pivIndex-1);
 quicksort(x, pivIndex+1, last);
 }
}

void printArray(int x[], int size) {

 int i;
 printf("x = {");
 for (i = 0; i < size; i++) {

 if (i == 0) {
 printf("%i", x[i]);
 } else {
 printf(", %i", x[i]);
 }
 }
 printf("}\n");
}

int main() {

 int vals1[1] = { 42 };
 int vals2[9] = { -5, 0, 1, 2, 4, 6, 8, 11, 20 };
 int vals3[9] = { 20, 11, 8, 6, 4, 2, 1, 0, -5 };
 int vals4[10] = { 3, 5, 1, 3, -2, 33, 2, 5, 9, 0 };

 quicksort(vals1, 0, 0);
 printf("Test 1.1: ");
 printArray(vals1, 1);

 quicksort(vals2, 0, 8);
 printf("Test 1.2: ");
 printArray(vals2, 9);

 quicksort(vals3, 0, 8);
 printf("Test 1.3: ");
 printArray(vals3, 9);

 quicksort(vals4, 0, 9);
 printf("Test 1.4: ");
 printArray(vals4, 10);

 return 0;
}
