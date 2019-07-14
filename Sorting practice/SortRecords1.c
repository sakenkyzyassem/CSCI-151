#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	char name[12];
} student;

void selectionSortById(student *x[], int size) {
    int i;
    for (i = 0; i < size - 1; i++) {
        int j, mindex = i;

        for (j = i + 1; j < size; j++) {
               if (x[j]->id < x[mindex]->id) {
                    mindex = j;
                }
        }

        student *temp = x[i];
        x[i] = x[mindex];
        x[mindex] = temp;
     }
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

void insertionSortByName(student *x[], int size) {
    int i, j;
    student *toInsert;

    for(i=0; i<size; i++){
        toInsert = x[i];
        for(j = i; j>=0; j--){
            if (j==0 || nameCompare(toInsert->name, x[j-1]->name) == 0){
                x[j] = toInsert;
                break;
            }
            else{
                x[j] = x[j-1];
            }
        }
    }
    /*int i, j; student *toInsert;
	for (i = 0; i < size; i++) {
		toInsert = x[i];

		for (j = i; j >= 0; j--) {
			if (j == 0 || nameCompare(x[j-1]->name, toInsert->name) == 1) {

				x[j] = toInsert;
				break;

			} else {
				x[j] = x[j - 1];
			}
		}
	}*/
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
	selectionSortById(roster, 8);

	// Printing out the roster, after sorting by id
	printArray(roster, 8);

        // Sorting the array by name (hopefully)
	insertionSortByName(roster, 8);

	// Printing out the roster, after sorting by name
	printArray(roster, 8);

	return 0;
}
