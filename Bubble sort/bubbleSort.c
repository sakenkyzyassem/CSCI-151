#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bubbleSort(int x[], int size) {
    int i, j, swap;

	for(i=size; i>=0; i--){
        swap = 0;
        for(j = 0; j < i; j++){
            if(x[j] > x[j+1]){
                int temp = x[j+1];
                x[j+1] = x[j];
                x[j] = temp;
                swap++;
            }
        }
    if(swap == 0)
        break;
	}
	/*for (i = 0; i < size - 1; i++) {

		for (j = 0; j < size - 1 - i; j++) {

			if (x[j]->id > x[j + 1]->id) {

				student *temp = x[j + 1];
				x[j + 1] = x[j];
				x[j] = temp;
			}
		}

	}*/
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

 bubbleSort(vals1, 1);
 printf("Test 1.1: ");
 printArray(vals1, 1);

 bubbleSort(vals2, 9);
 printf("Test 1.2: ");
 printArray(vals2, 9);

 bubbleSort(vals3, 9);
 printf("Test 1.3: ");
 printArray(vals3, 9);

 bubbleSort(vals4, 10);
 printf("Test 1.4: ");
 printArray(vals4, 10);

 return 0;
}
