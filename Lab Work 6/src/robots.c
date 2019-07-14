#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	_Bool hasRobot; // 1 (true) a robot is here; 0 (false) the space is clear
	int robHeading; // 0 (west), 1 (north), 2 (east), 3 (south)
	_Bool robAlive; // 1 (true) for running robot; (false) when crashed
} gridSquare;

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);

	// The 10 by 10 grid
	gridSquare grid[10][10];
	int j, k;
	for(j=0; j<10; j++){
		for(k = 0; k <10; k++){
			grid[j][k].hasRobot = 0;
			grid[j][k].robAlive = 0;
		}
	}
	// TODO: initialize the grid using a nested loop so there are no robots


	int i;
	int row, column;
	char cmd;

	// Add 10 robots to the grid
	for (i = 0; i < 10; i++) {

		// This makes sure that the grid space is currently empty
		do {
			row = rand() % 10;
			column = rand() % 10;
		} while (grid[row][column].hasRobot == 1);

		grid[row][column].hasRobot = 1;
		grid[row][column].robAlive = 1;
		grid[row][column].robHeading= rand()%4;
	}
		// TODO:  Randomly set the heading at (column,row),
		//        and make the robot alive

	// Counts the number of live robots
	int liveCount = 10;

	// main loop of the game
	do {

		for(j = 0; j<10; j++){
			for(k=0; k<10; k++){
				if(grid[j][k].hasRobot == 1 && grid[j][k].robAlive ==1){
							printf("R ");}
				else if (grid[j][k].hasRobot ==1 && grid[j][k].robAlive == 0){
							printf("@ ");}
				else {
							printf(". ");}
					}
			printf("%i \n", j);
		}
		printf("0 1 2 3 4 5 6 7 8 9");

		// TODO: Output the grid

		// Obtain user input (move or rotate command)
		printf("\n input action and coordinates, please: ");
		scanf(" %c %i %i", &cmd, &row, &column);

		// Process user command
		if (grid[row][column].hasRobot && grid[row][column].robAlive) {

			if (cmd == 'L') {
				if(grid[row][column].robHeading == 0){
					grid[row][column].robHeading = 3;
				}
				else{
					grid[row][column].robHeading = grid[row][column].robHeading-1;
				}
				printf("Robot turned left\n");
				// TODO: Update the heading accordingly
			}
			else if (cmd == 'R') {
				if(grid[row][column].robHeading == 3){
					grid[row][column].robHeading = 0;
				}
				else{
					grid[row][column].robHeading = grid[row][column].robHeading+1;
				}
				printf("Robot turned right\n");
				// TODO: Update the heading accordingly

			} else if (cmd == 'F') {
				int new;
				// This attempts to move the robot forward, depending on the
				// direction it is currently pointing
				switch (grid[row][column].robHeading) {

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

					case 3: // Pointing south
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
				}

			}

		}

	} while (liveCount > 0);

	printf("All of the robots are crashed!");

	return 0;
}

