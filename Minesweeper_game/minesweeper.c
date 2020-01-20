#include <stdio.h>
#include <stdlib.h>

typedef struct{
	_Bool is_there;
	_Bool view, flag;
	int count;
}mine;

typedef struct{
	int row, column, mine, free_cell;
}options;

void initializing(options op, mine m[op.row][op.column]){
	int i, j;

	for(i=0; i < op.row; i++){
		for(j=0; j < op.column; j++){
			m[i][j].is_there = 0;
			m[i][j].view = 0;
			m[i][j].flag = 0;
		}
	}
}

void mineGenerate(options op, mine m[op.row][op.column]){
	int i, row, column;
	for (i = 0; i < op.mine; i++) {
		do {
			row = rand() % op.row;
			column = rand() % op.column;
		} while (m[row][column].is_there == 1);
		m[row][column].is_there = 1;
	}
}

void map (options op, mine m[op.row][op.column]){
	int i, j;
	printf("\n  ");
	for(i=0; i<op.column; i++)
	printf("%3i", i);

	for(i=0; i < op.row; i++){
		printf("\n%i ", i);
		for(j=0; j < op.column; j++){
				if(m[i][j].is_there == 0 && m[i][j].view == 1)
					printf("  %i", m[i][j].count);
				else if(m[i][j].is_there == 0 && m[i][j].view == 0)
					printf("  .");
				else if (m[i][j].is_there == 1 && m[i][j].view == 1)
					printf("  *");
				else if (m[i][j].is_there == 1 && m[i][j].view == 0)
					printf("  .");
			}
	}

}

void addProximities(options op, mine m[op.row][op.column]){
	int i, j, count, n, k;

	for(i = 0; i<op.row; i++){
		for(j = 0; j < op.column; j++){
			count = 0;
			for(n = i-1; n<=i+1;n++){
				if(n>=0 && n<op.row){
					for(k = j-1; k<=j+1; k++){
						if(k>=0 && k<op.column){
							if(m[n][k].is_there == 1)
							count++;}
					}
				}
			}
		m[i][j].count = count;
		}
	}

}

void playingTheGame(options op, mine m[op.row][op.column]);

int WinMain() {
	setvbuf(stdout, NULL, _IONBF, 0);

	options op;

	printf("How much rows do you prefer: ");
	scanf("%i", &op.row);
	printf("Column: ");
	scanf("%i", &op.column);
	printf("Number of mines: ");
	scanf("%i", &op.mine);

	mine mm[op.row][op.column];

	initializing(op, mm);
	mineGenerate(op, mm);
	addProximities(op, mm);
	map(op, mm);
	playingTheGame(op, mm);

	return 0;
}

void mapPrinting (options op, mine m[op.row][op.column]){
	int i, j;
	printf("\n  ");
	for(i=0; i<op.column; i++)
	printf("%3i", i);

	for(i=0; i < op.row; i++){
		printf("\n%i ", i);
		for(j=0; j < op.column; j++){
				if(m[i][j].is_there == 0 && m[i][j].view == 1)
					printf("  %i", m[i][j].count);
				else if(m[i][j].is_there == 0 && m[i][j].view == 0 && m[i][j].flag == 0)
					printf("  ?");
				else if (m[i][j].is_there == 1 && m[i][j].view == 1)
					printf("  *");
				else if (m[i][j].is_there == 1 && m[i][j].view == 0 && m[i][j].flag == 0)
					printf("  ?");
				else if (m[i][j].is_there == 1 && m[i][j].view == 0 && m[i][j].flag == 1)
					printf("  F");
				else if(m[i][j].is_there == 0 && m[i][j].view == 0 && m[i][j].flag == 1)
					printf("  F");
			}
	}

}

void addingFlags(options op, mine m[op.row][op.column]){
	char ch[25], x;
	int r, c;
	printf("\nWould you like to add a flag? \n");
	printf("if 'Yes': y, if 'No': n\n");
	scanf("%s", ch);
	x = ch[0];

	switch( x ){

	case 'y':
		printf("Where do you want to add a flag?\n");
		scanf("%i", &r);
		scanf("%i", &c);
		m[r][c].flag = 1;
		break;
	case 'n':
		break;
	default:
		printf("Incorrect input, see ya!\n");
		break;
	}
}

void playingTheGame(options op, mine m[op.row][op.column]){
	int coor_r, coor_c, i, j, k = 0;
	_Bool game = 1;
	op.free_cell = op.column * op.row - op.mine;

	do{
		op.free_cell--;
		puts("");
		if(k>0)
			addingFlags(op, m);
		printf("Write the number of row and column you want to uncover:\n");
		scanf("%i ", &coor_r);
		scanf("%i", &coor_c);

			if(coor_r < op.row && coor_c < op.column){
				if(m[coor_r][coor_c].is_there ==0){
				m[coor_r][coor_c].view = 1;
				}
				else {
					printf("BOOOOOM!!!\n");
					for(i=0;i<op.row;i++){
						for(j=0;j<op.column;j++)
							m[i][j].view = 1;}
					game = 0;
				}
			mapPrinting(op, m);
			}
			else
				printf("Row and/or Column numbers are not within the range");

		if (op.free_cell == 0)
			game = 0;

		k++;
		}while(game != 0);

	printf("\nYou lost the game!");
}
