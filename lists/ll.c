#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 80

typedef struct node
{
	char *word;
	struct node *next;
} WNode;


void insert_in_order( WNode **head, char *buf )
{
	WNode *p, *prev, *new;
	int ret;

	new = (WNode *) malloc( sizeof(WNode) );
	new->word = (char *) malloc( strlen(buf)+1 );
	new->next = NULL;
	strcpy( new->word, buf );

	// IF list is empty
	if ( *head == NULL )
	{
		*head = new;
		return;
	}
	// IF this node goes on the front
	if ( strcmp( new->word, (*head)->word ) >= 0 )
	{
		new->next = *head;
		*head = new;
		return;
	}
	// FIND the place
	for ( p = *head, prev = p; 
		(ret = strcmp(new->word, p->word)) < 0 && p->next != NULL; 
		p = p->next )
	{
		prev = p; // just keep going until your spot or the end
	}
	// It's the end
	if ( ret < 0 )
		p->next = new;
	// It's the middle
	else
	{
		new->next = prev->next;
		prev->next = new;
	}

}
			

int main()
{
	WNode *head = NULL;
	WNode *p;
	int i;
	char buf[MAXLINE];
	
	while ( fgets( buf, MAXLINE, stdin) != NULL )
	{
		insert_in_order( &head, buf );
		printf( "Enter a word:\n" );
	}

	printf( "In order.\n" );
	for ( p = head; p != NULL; p = p->next )
		printf( "%s", p->word ); 

}




