#include <stdio.h>

void selectionSort(int x[], int size) {
	int i, j, min=0;

	for(i=0; i<size-1; i++){
		min = i;
		for(j=i+1; j<size; j++){
			if(x[min]>x[j]){
				min = j;}
		}
		int temp = x[min];
		x[min] = x[i];
		x[i] = temp;
	}


	/*int i;
     for (i = 0; i < size - 1; i++) {

          int j, mindex = i;
          for (j = i + 1; j < size; j++) {
               if (x[j] < x[mindex]) {
                    mindex = j;
    }
          }

          int temp = x[i];
          x[i] = x[mindex];
          x[mindex] = temp;
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

 int vals1[1] = {42};
 int vals2[9] = {-5, 0, 1, 2, 4, 6, 8, 11, 20};
 int vals3[9] = {20, 11, 8, 6, 4, 2, 1, 0, -5};
 int vals4[10] = {3, 5, 1, 3, -2, 33, 2, 5, 9, 0};

 selectionSort(vals1, 1);
 printf("Test 1.1: ");
 printArray(vals1, 1);

 selectionSort(vals2, 9);
 printf("Test 1.2: ");
 printArray(vals2, 9);

 selectionSort(vals3, 9);
 printf("Test 1.3: ");
 printArray(vals3, 9);

 selectionSort(vals4, 10);
 printf("Test 1.4: ");
 printArray(vals4, 10);


 return 0;
}
