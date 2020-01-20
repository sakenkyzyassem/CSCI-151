#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	_Bool hasRobot; // 1 (true) a robot is here; 0 (false) the space is clear
	int robHeading; // 0 (west), 1 (north), 2 (east), 3 (south)
	_Bool robAlive; // 1 (true) for running robot; (false) when crashed
} gridSquare;

//TODO: implement the following functions

/**
 * Initialize the grid of size s so that there are no robots initially
 */
void gridInit(int s, gridSquare grid[s][s]){
	int j, k;
		for(j=0; j<s; j++){
			for(k = 0; k <s; k++){
				grid[j][k].hasRobot = 0;
				grid[j][k].robAlive = 0;
			}
		}
}
/**
 * Print the grid: put directions according to robHeading
 * and . if there is no robot at the specified cell
 */
void printGrid(int s, gridSquare grid[s][s]){
	int i, j;

	for(i=0; i<s; i++){
		for(j=0; j<s; j++){
			if(grid[i][j].hasRobot == 1 && grid[i][j].robAlive ==1){
				printf("R ");}
			else if (grid[i][j].hasRobot ==1 && grid[i][j].robAlive == 0){
				printf("@ ");}
			else{
				printf(". ");}
	}
	printf(" %i\n", i);}
	printf("0 1 2 3 4 5 6 7 8 9");
}

/**
 * Randomly add robots to the grid.
 * Make sure to generate robots only if the number robots to add can fit the grid.
 * In other words, quantity should be less than the area of the grid.
 */
void addRobots(int quantity, int size, gridSquare grid[size][size]){
	int i, row, column;
	for (i = 0; i < quantity; i++) {
			do {
				row = rand() % size;
				column = rand() % size;
			} while (grid[row][column].hasRobot == 1);

			grid[row][column].hasRobot = 1;
			grid[row][column].robAlive = 1;
			grid[row][column].robHeading= rand()%4;
		}
}

/**
 * Rotate the robot anti-clockwise.
 * Update the heading accordingly.
 * row and column here are the user input.
 */
void rotateLeft(int row, int column, int size, gridSquare grid[size][size]){
	if(grid[row][column].robHeading == 0){
		grid[row][column].robHeading = 3;
	}
	else{
		grid[row][column].robHeading = grid[row][column].robHeading-1;
	}
	printf("Robot turned left\n");
}

/**
 * Rotate the robot clockwise.
 * Update the heading accordingly.
 * row and column here are the user input.
 */
void rotateRight(int row, int column, int size, gridSquare grid[size][size]){
		if(grid[row][column].robHeading == 3){
					grid[row][column].robHeading = 0;}
		else{
					grid[row][column].robHeading = grid[row][column].robHeading+1;}
		printf("Robot turned right\n");
}
/**
 * OPTIONAL: move the robot at row, column forward
 */
void moveForward(int row, int column, int s, gridSquare grid[s][s]){

}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);

	// The 10 by 10 grid
	int s = 10;
	gridSquare grid[s][s];

	// TODO: initialize the grid using the gridInit function defined above
	gridInit(s, grid);


	int row, column;
	int number_of_robots = 10; //could be any number that can fit to the grid.

	// Add 10 robots to the grid using a function
	addRobots(number_of_robots, s, grid);


	// Counts the number of live robots
	int liveCount = 10;

	// main loop of the game
	do {

		// TODO: Output the grid using the printing function
		printGrid(s, grid);

		char cmd;

		// Obtain user input (move or rotate command)
		printf("\n input action and coordinates, please: ");
		scanf(" %c %i %i", &cmd, &row, &column);

		// Process user command
		if (grid[row][column].hasRobot && grid[row][column].robAlive) {

			if (cmd == 'L') {
			rotateLeft(row, column, s, grid);

			}else if (cmd == 'R') {
			rotateRight(row, column, s, grid);

			}else if (cmd == 'F') {

				// This attempts to move the robot forward, depending on the
				// direction it is currently pointing
			switch (grid[row][column].robHeading) {
			int new;
					case 0: // Pointing west
						if (column > 0) {
													new = column - 1;
													if(grid[row][new].hasRobot == 1 && grid[row][new].robAlive == 1){
														printf("Crash!\n");
														grid[row][new].hasRobot = 1;
														grid[row][column].hasRobot = 1;
														grid[row][new].robAlive =0;
														grid[row][column].robAlive =0;
														liveCount = liveCount - 2;}
													else if (grid[row][new].hasRobot == 0){
														printf("Robot moved forward\n");
														grid[row][new].hasRobot = 1;
														grid[row][column].hasRobot = 0;
														grid[row][new].robAlive = 1;
														grid[row][column].robAlive = 0;
														grid[row][new].robHeading = 0;
													}
													else if (grid[row][new].hasRobot == 1 && grid[row][new].robAlive == 0){
														printf("Crash!\n");
														grid[row][new].hasRobot = 1;
														grid[row][column].hasRobot = 1;
														grid[row][new].robAlive =0;
														grid[row][column].robAlive =0;
														liveCount--;}
													// TODO: If a robot is in front of you, crash both;
													// otherwise move the robot forward
												}
							break;
					case 1: // Pointing north
						if (row > 0) {
													new = row - 1;
													if(grid[new][column].hasRobot == 1 && grid[new][column].robAlive == 1){
															printf("Crash!\n");
															grid[new][column].robAlive =0;
															grid[row][column].robAlive =0;
															grid[new][column].hasRobot = 1;
															grid[row][column].hasRobot = 1;
															liveCount = liveCount -2;}
													else if (grid[new][column].hasRobot == 0){
														printf("Robot moved forward\n");
															grid[new][column].hasRobot =1;
															grid[new][column].robAlive =1;
															grid[row][column].hasRobot =0;
															grid[row][column].robAlive =0;
															grid[new][column].robHeading = 1;}
													else if (grid[new][column].hasRobot == 1 && grid[new][column].robAlive == 0){
															printf("Crash!\n");
															grid[new][column].robAlive =0;
															grid[row][column].robAlive =0;
															grid[new][column].hasRobot = 1;
															grid[row][column].hasRobot = 1;
															liveCount--;}
													// TODO: If a robot is in front of you, crash both;
													// otherwise move the robot forward
												}
							break;
					case 2: // Pointing east
						if (column < 9) {
													new = column + 1;
													if(grid[row][new].hasRobot == 1 && grid[row][new].robAlive == 1){
															printf("Crash!\n");
															grid[row][new].robAlive =0;
															grid[row][column].robAlive =0;
															grid[row][new].hasRobot = 1;
															grid[row][column].hasRobot = 1;
															liveCount = liveCount - 2;}
													else if (grid[row][new].hasRobot == 0){
														printf("Robot moved forward\n");
															grid[row][column].hasRobot =0;
															grid[row][column].robAlive = 0;
															grid[row][new].hasRobot =1;
															grid[row][new].robAlive = 1;
															grid[row][new].robHeading = 2;}
													else if(grid[row][new].hasRobot == 1 && grid[row][new].robAlive == 0){
															printf("Crash!\n");
															grid[row][new].robAlive =0;
															grid[row][column].robAlive =0;
															grid[row][new].hasRobot = 1;
															grid[row][column].hasRobot = 1;
															liveCount--;}
													// TODO: If a robot is in front of you, crash both;
													// otherwise move the robot forward
												}
							break;
					case 3: //Pointing south
						if (row < 9) {
													new = row+1;
													if(grid[new][column].hasRobot == 1 && grid[new][column].robAlive == 1){
															printf("Crash!\n");
															grid[new][column].robAlive =0;
															grid[row][column].robAlive =0;
															grid[new][column].hasRobot = 1;
															grid[row][column].hasRobot = 1;
															liveCount = liveCount - 2;}
													else if (grid[new][column].hasRobot == 0){
														printf("Robot moved forward\n");
															grid[row][column].hasRobot = 0;
															grid[row][column].robAlive = 0;
															grid[new][column].hasRobot = 1;
															grid[new][column].robAlive = 1;
															grid[new][column].robHeading = 3;}
													else if(grid[new][column].hasRobot == 1 && grid[new][column].robAlive == 0){
															printf("Crash!\n");
															grid[new][column].robAlive =0;
															grid[row][column].robAlive =0;
															grid[new][column].hasRobot = 1;
															grid[row][column].hasRobot = 1;
															liveCount--;}
													// TODO: If a robot is in front of you, crash both;
													// otherwise move the robot forward
												}
							break;

					default: // Shouldn't happen
						break;

						printf("Ok,Robot moved forward ");

				}
			}
		}

	} while (liveCount > 0);

	return 0;

				}
