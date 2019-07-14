#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int id;
	char name[41];
} student;

const int size = 8;

const student roster[8] =
		{{ 100001, "Ziggy Marley" },
		{ 123456, "Abe Lincoln" },
		{ 239484, "Jed Clampett" },
		{ 443892, "Marge Simpson" },
		{ 517840, "Betty Britain" },
		{ 780556, "David Bowie" },
		{ 900154, "Gore Vidal" },
		{ 999900, "Nursultan Jones" } };

int findStudent(int id) {
	int i;

	for(i=0; i<8; i++){
		if(roster[i].id == id){
			return i;}
	}
	return -1;
}

int main(void) {

	printf("Test 0: %i \n", findStudent(99));
	printf("Test 1: %i \n", findStudent(100001));
	printf("Test 2: %i \n", findStudent(123456));
	printf("Test 3: %i \n", findStudent(300000));
	printf("Test 4: %i \n", findStudent(780556));
	printf("Test 5: %i \n", findStudent(999900));
	printf("Test 6: %i \n", findStudent(999999));

	return 0;
}
