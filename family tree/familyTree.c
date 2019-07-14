#include <stdlib.h>
#include <stdio.h>

typedef struct _person{
	char *name;
	struct _person *mother;
	struct _person *father;
} person;

char* nameReader() {

	char *name = malloc(40*sizeof(char) + 1);
	if (name == NULL) { exit(1); }
	
	char *nptr = name;

	char ch = getchar();
	while (ch != '\n' && ch != EOF) {
		*nptr = ch;
		nptr++;
		ch = getchar();
	}
	*nptr = '\0';

	return name;
}

person* personBuilder(char *name) {

	person *result = (person*)malloc(sizeof(person));
	if (result == NULL) { exit(1); }
		
	result->name = name;

	printf("What is %s's father's name? (Press <Enter> if not known)", name);
	char *fname = nameReader();

	if (*fname != '\0') {
		result->father = personBuilder(fname);
	} else {
           free(fname);
		result->father = NULL;
	}

	printf("What is %s's mother's name? (Press <Enter> if not known)", name);
	char *mname = nameReader();

	if (*mname != '\0') {
		result->mother = personBuilder(mname);
	} else {
           free(mname);
		result->mother = NULL;
	}

	return result;
}

void printFamilyTree(person *p, char* title, int indent) {

	int i;
	for (i = 0; i < indent; i++) {
		putchar(' ');
	}
	if (p == NULL) {
		printf("%s: %s\n", title, "UNKNOWN");
		return;
	}

	printf("%s: %s\n", title, p->name);

	printFamilyTree(p->father, "Father", indent + 3);
	printFamilyTree(p->mother, "Mother", indent + 3);

}

void freeTree(person *p) {

	if (p == NULL) {
		return;
	}

	freeTree(p->father);
	freeTree(p->mother);

	printf("Freeing memory for %s\n", p->name);
	free(p->name);
	free(p);
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	printf("What is your name? ");
	char *name = nameReader();

	person *me = personBuilder(name);

	printf("\n");
	printFamilyTree(me, "Me", 0);

	printf("\n");
	freeTree(me);

	return 0;
}
