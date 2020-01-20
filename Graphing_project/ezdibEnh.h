// TODO: Maybe need to include something?

// TODO: Need to add header guards

// Colors are represented as int's in hex form
#define Color int

/* Plots a triangle with line color lineClr with
 * vertices (x1, y1), (x2, y2), and (x3, y3)
 */
void my_triangle(HEZDIMAGE hDib,
					int x1, int y1,
					int x2, int y2,
					int x3, int y3,
					Color lineClr);
/*
 * Plots a rhombus with line color lineClr whose
 * axes are parallel with the x- and y-axes, with
 * center (xCenter, yCenter), with the given height
 * and width
 */
void my_diamond(HEZDIMAGE hDib,
					int xCenter, int yCenter,
					int height, int width,
					Color lineClr);
