#include <stdio.h>

int main(void) {
	int checkerboard [8][8];
	
	// solution using for-loops
	
	// determine length of rows and columns - boundings for the for-loops
	int row_length = sizeof(checkerboard) / sizeof(checkerboard[0]);
	int col_length = sizeof(checkerboard[0]) / sizeof(checkerboard[0][0]);
		
	// double num, when (rows + cols) % 2 == 0 (when computed value is even)
	int num = 1;
	for(int rows = 0; rows < row_length; rows++) {
		for(int cols = 0; cols < col_length; cols++) {
			if((rows + cols) % 2 == 0) {
				checkerboard[rows][cols] = num;
				num *= 2;
			} else {
				checkerboard[rows][cols] = 0;
			}
		}
	}
	

	// printing board 
	printf("solution for using for-loops:\n");
	
	for(int rows = 0; rows < row_length; rows++) {
		for(int cols = 0; cols < col_length; cols++) {
			printf("%d\t", checkerboard[rows][cols]);
		}
		printf("\n");
	}
	
	printf("\n\n");
	
	// solution using while-loops
	int rows = 0;
	int cols = 0;
	num = 1;
	// double num, when (rows + cols) % 2 == 0 (when computed value is even)
	while(rows < row_length) {
		while(cols < col_length) {
			if((rows + cols) % 2 == 0) {
				checkerboard[rows][cols] = num;
				num *= 2;
			} else {
			  checkerboard[rows][cols] = 0;
			}
			cols += 1;
		}
		rows += 1;
	}
		
	// resetting values
	rows = 0;
	cols = 0;
	
	
	// printing board
	printf("solution for using while-loops:\n");
	
	while(rows < row_length) {
		while(cols < col_length) {
			printf("%d\t", checkerboard[rows][cols]);
			cols += 1;
		}
		printf("\n");
		cols = 0;
		rows += 1;
	}
	
}
