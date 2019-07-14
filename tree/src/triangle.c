#include <stdio.h>

int WinMain() {

	int j;
	int star;
	int space;

	for(j = 0; j <= 6; j++){

		for (space = 0; space <= 13-j; space++){
			printf(" ");
		}
		for (star = 1; star <= 2*j+1; star++){
			printf("*");
	}
	printf("\n");
	}

	for(j = 0; j <= 3; j++){

			for (space = 0; space <= 9-2*j; space++){
				printf(" ");
			}
			for (star = 0; star <= 4*j+8; star++){
				printf("*");
		}
		printf("\n");
		}

	for(j = 0; j <= 3; j++){

				for (space = 0; space <= 7-2*j; space++){
					printf(" ");
				}
				for (star = 0; star <= 4*j+12; star++){
					printf("*");
			}
			printf("\n");
			}

	for(j = 0; j <= 3; j++){

				for (space = 0; space <= 5-2*j; space++){
					printf(" ");
				}
				for (star = 0; star <= 4*j+16; star++){
					printf("*");
			}
			printf("\n");
			}

	for (j = 1; j < 4; j++) {

		for (space = 0; space < 1; space++) {
			printf ("          ");

		}
		for (star = 0; star < 1; star++) {
			printf ("*********"); }

		printf("\n");

	}

	return 0;

}
