#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x) {
	return -2 * x * x * x - x + 2;
}

double zeroFinder(double min, double max, double error) {
    double guess;
    guess = (min+max)/2.0;

        if(func(guess)<error/100 && max - min >= error)
            return guess;
        else if(func(guess)> 0.0 && max - min >= error)
            return zeroFinder(guess+error, max, error);
        else if(func(guess)< 0.0 && max - min >= error)
            return zeroFinder(min, guess-error, error);
        else
            return -1.0;
}

int main(void) {

	// Testing code
	printf("zero:%f \n", zeroFinder(0.0, 1.0, 0.01));
	printf("zero:%f \n", zeroFinder(0.0, 1.0, 0.001));
	printf("zero:%f \n", zeroFinder(0.0, 1.0, 0.000001));
	printf("zero:%f \n", zeroFinder(0.0, 1.0, 0.0000000001));

	return 0;
}
