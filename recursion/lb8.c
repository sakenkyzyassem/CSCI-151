#include <stdio.h>
#include <string.h>

int maxValue(int arr[], int from, int to){
	if(arr[from] > arr[to]){
		return maxValue(arr, from, to-1);
	} else if(arr[from] < arr[to]){
		return maxValue(arr, from+1, to);
	}
	else
		return arr[from];
}

int factorialN(int n){
	if(n==1 || n == 0)
		return 1;
	else
		return factorialN (n-1) * n;
}

int charCmp(int a, int b){
	if(a == b)
		return 0;
	else if(a < b)
		return -1;
	else
		return 1;
}

int stringCmp(char string1[], char string2[]){
	int i, len1, len2, val;
	len1 = strlen(string1);
	len2 = strlen(string2);

	if(len1 > len2){
		for(i=0; i<len1; i++){
			val = charCmp((unsigned char)string1[i] ,(unsigned char)string2[i]);}
	}
	else if(len1 < len2){
		for(i=0; i<len2; i++){
			val = charCmp((unsigned char)string1[i], (unsigned char)string2[i]);}
	}
	else if (len1 == len2){
		for(i=0; i < len1; len1++){
			val = charCmp((unsigned char)string1[i], (unsigned char)string2[i]);}
	}
	return val;
}

int WinMain(){

	setvbuf(stdout, NULL, _IONBF, 0);
//Task 1
	int array[7] = {2, 6, 5, 8, 1, 3, 24};
	int ans;

	ans = maxValue(array, 0, 6);
	printf("Task 1: %i\n", ans);

//Task 2
	long int n = 10, k = 4;
	long int answ;

	answ = factorialN(n) / (factorialN(k) * factorialN(n-k));

	printf("Task 2: %ld\n", answ);

//Task 3

	char st1[60]="apple", st2[60] = "application";

	ans = stringCmp(st1, st2);
	printf("Task 3: %i\n", ans);

//Task 4
	/* a = 11
	 * b = 20
	 * x = 97
	 * y = 88
	 * ip1 = address of x
	 * ip2 = address of b
	 * ipp = address of *ip2
	 * *ip1 = 97
	 * *ip2 = 20
	 * *ipp = address of b
	 * **ipp = 20
	 */
	return 0;
}
