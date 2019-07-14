#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS 100000
#define MAXLINE 80


void scoot_twod( int from, int to, char words[][MAXLINE] )
{
	int i;

	for ( i = to; i > from; i-- )
		strcpy( words[i], words[i-1] );
}


void scoot_aofp( int from, int to, char *words[] )
{
	int i;

	for ( i = to; i > from; i-- )
		words[i] = words[i-1];
}


void insert_in_order_twod( char *buf, char words[][MAXLINE], int n )
{
	int i, j;

	for ( i = 0; (i < n) && (strcmp(buf, words[i]) <= 0); i++ )
	{
		; // just loop until you reach the right place
	}
	if ( i < n )
		scoot_twod( i, n, words );
	strcpy( words[i], buf );
}
			
void insert_in_order_aofp( char *p, char *words[], int n )
{
	int i, j;

	for ( i = 0; (i < n) && (strcmp(p, words[i]) <= 0); i++ )
	{
		; // just loop until you reach the right place
	}
	if ( i < n )
		scoot_aofp( i, n, words );
	words[i] = p;
}

int main()
{
	int count = 0;
	int i;
	char buf[MAXLINE];

	/*
	char array2D[ROWS][MAXLINE];

        while ( fgets( buf, MAXLINE, stdin) != NULL )
        {
                insert_in_order_twod( buf, array2D, count );
                count++;
                if ( count == ROWS )
                        break;
        	printf( "Enter a word:\n" );
        }

	printf( "In order:\n" );
	for ( i = 0; i < count; i++ )
                printf( "%s", array2D[i]);

	*/

	char *ptrs[ROWS];
	char *p;
	
	while ( fgets( buf, MAXLINE, stdin) != NULL )
	{
		p = (char *) malloc( strlen(buf)+1 );
		strcpy( p, buf );	
		insert_in_order_aofp( p, ptrs, count );
		count++;
		if ( count == ROWS )
			break;
		printf( "Enter a word:\n" );
	}
	printf( "In order:\n" );
	for ( i = 0; i < count; i++ )
		printf( "%s", ptrs[i]);

}




