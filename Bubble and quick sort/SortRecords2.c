#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	char name[12];
} student;

void bubbleSortById(student *x[], int size) {
    int i, j, swap;

	for(i=size; i>=0; i--){
        swap = 0;
        for(j = 0; j < i; j++){
            if(x[j]->id > x[j+1]->id){
                student *temp = x[j+1];
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

_Bool nameCompare(char name1[], char name2[]) {

	int i = 0;
	do {
		if (name1[i] < name2[i]) {
			return 1;
		} else if (name1[i] > name2[i]) {
			return 0;
		}
		i++;
	} while (name1[i] != '\0' || name2[i] != '\0');

	return 0;
}

int partitionByName(student *x[], int first, int last) {

    int pivot = first;

    int up = first, down = last;
    while (up < down) {

        while (nameCompare(x[pivot]->name, x[up]->name) == 0 && up < last) {
            up++;}
        while (nameCompare(x[pivot]->name, x[down]->name) == 1) {
            down--;}
        if (up < down) {
            student *temp = x[up];
            x[up] = x[down];
            x[down] = temp;
        }
    }

     student *temp2 = x[pivot];
     x[pivot] = x[down];
     x[down] = temp2;

    return down;
}

void quicksortByName(student *x[], int first, int last) {

    if (first < last) {
         int pivIndex = partitionByName(x, first, last);
         quicksortByName(x, first, pivIndex-1);
         quicksortByName(x, pivIndex+1, last);
         }
}

void printArray(student *x[], int size) {

	int i;
	for (i = 0; i < size; i++) {
		printf("%8i %12s \n", x[i]->id, x[i]->name);
	}
	printf("\n");
}

int main() {

	student *roster[8];

	// Opening the input file
	FILE *file = fopen("records.txt", "r");
	if (file == NULL) {
		printf("Cannot find file.");
		exit(1);
	}
	printf("File opened successfully.\n");

	// Reading the records into the roster from the file
	int i;
	for (i = 0; i < 8; i++) {
		roster[i] = malloc(sizeof(student));
		fscanf(file, "%i %s \n", &roster[i]->id, roster[i]->name);
	};
	fclose(file);

	// Printing out the roster, in the initial order
	printArray(roster, 8);

	// Sorting the array by id (hopefully)
	bubbleSortById(roster, 8);

	// Printing out the roster, after sorting by id
	printArray(roster, 8);

	// Sorting the array by name (hopefully)
	quicksortByName(roster, 0, 7);

	// Printing out the roster, after sorting by name
	printArray(roster, 8);

	return 0;
}
