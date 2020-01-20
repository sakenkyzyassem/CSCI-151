
#include <stdio.h>
#include <stdlib.h>
#include "ezdib.h"


int main( int argc, char* argv[] )
{
	// Create an image
	HEZDIMAGE hDib = ezd_create( 640, -480, 24, 0);

	// Fill in the background with a dark gray color
	ezd_fill( hDib, 0x606060 );

	//yellow box
	ezd_fill_rect( hDib, 200, 100, 440, 360, 0xffff00 );

	// Line
	ezd_line( hDib, 240, 140, 400, 137, 0x0011ff );

	// Rectangle
	ezd_rect( hDib, 240, 280, 400, 295, 0x000000 );

	// Circle
	ezd_circle( hDib, 270, 180, 25, 0xff0000 );

	// Fill the circle
	ezd_flood_fill( hDib, 270, 180, 0x00ff00, 0xff0000 );

	// Circle
	ezd_circle( hDib, 370, 180, 25, 0xff0000 );

	// Fill the circle
	ezd_flood_fill( hDib, 370, 180, 0xff0000, 0xff0000 );

	
	// Save a test image
	ezd_save( hDib, "test.bmp" );

	// Free resources
	ezd_destroy( hDib );
	return 0;
}
