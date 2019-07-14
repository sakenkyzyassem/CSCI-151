#include <stdio.h>

int findInt(int x[], int size, int key){
    int i;

    for(i=0; i<size; i++){
        if(x[i] == key)
            return i;
        else
            return -1;
    }
}

int binarySearch(int x[], int size, int key) {

    int min = 0;
    int max = size-1;

    while (min <= max) {

        int guess = (min + max) / 2;

        if (x[guess] == key) {
            return guess;
        } else if (x[guess] > key) {
            max = guess - 1;
        } else { // if (x[guess] < key)
            min = guess + 1;
        }

    }

    return -1;
}

int main(void){
    setvbuf(stdout, NULL, _IONBF, 0);

    int arr[10]={-50, 0, 25, -80, 90, 10, 65, -100, 74, 2};

    printf("%i", binarySearch(arr, 10, -80));

    return 0;
}
