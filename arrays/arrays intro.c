/*
### Task 1

 - First 11 Fibonacci numbers

### Task 2

 - Prints 20 random numbers between 50 and 100
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {

	setvbuf(stdout, NULL, _IONBF, 0);
/*
 * 1 task
 */
	int i;
	int a[11];

	a[1]=1;
	for(i=0; i<11; i++){
		if(i<=1){
			a[i] = 1;
			printf("1, ");}
		else{
			a[i] = a[i-2]+a[i-1];
			printf("%i, ", a[i]);}
	}

/*
 * 2 task
 */
	puts("");
	int val[20];
	int r, m;
	srand(time(NULL));
	i = 0;
	for(m=0; i<20; m++){
		r = rand()%101;
		if(r>=50 && r<=100){
			val[i] = r;
			printf("%i\n", val[i]);
			i++;}
	}
	return 0;
}

