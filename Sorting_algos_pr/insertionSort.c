#include <stdio.h>

void insertionSort(int x[], int size) {

	int i, j, toInsert;
	for (i = 0; i < size; i++) {
		toInsert = x[i];

		for (j = i; j >= 0; j--) {
			if (j == 0 || x[j-1] <= toInsert) {

				x[j] = toInsert;
				break;

			} else {
				x[j] = x[j - 1];
			}
		}
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

 insertionSort(vals1, 1);
 printf("Test 1.1: ");
 printArray(vals1, 1);

 insertionSort(vals2, 9);
 printf("Test 1.2: ");
 printArray(vals2, 9);

 insertionSort(vals3, 9);
 printf("Test 1.3: ");
 printArray(vals3, 9);

 insertionSort(vals4, 10);
 printf("Test 1.4: ");
 printArray(vals4, 10);

 return 0;
}
