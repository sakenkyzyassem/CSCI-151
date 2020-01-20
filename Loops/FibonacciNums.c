#include <stdio.h>

int main (void) {

	int j = 0;
	int var0 = 0;
	int var1 = 1;
	int s;

	setvbuf (stdout, NULL, _IONBF, 0);

	printf ("%i %i ", var0, var1);
	while (j < 18) {

		s = var0 + var1;

		printf("%i ", s);

		var0 = var1;
		var1 = s;
		j++;
	}

	return 0;
}
