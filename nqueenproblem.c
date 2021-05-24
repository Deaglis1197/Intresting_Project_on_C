#include <stdio.h>
#include <stdbool.h>
#define N 8
int board[N][N] = { 0 };
int counter = 1;

bool issafe(int row,int col){/*safe place testing for queen*/
	int i, j;

	/* left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/* lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}
void printboard() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}
void nqueensolve(int col) {
	
	if (col == N) { /*if place all queen,print table*/
		printf("Solve = %d\n",counter++);
		printboard();
		printf("\n");
		return;
	}
	
	else{
		for (int i = 0; i < N; i++) {
			if (issafe(i, col)) {
				board[i][col] = 1;/*if is safe, place queen*/
				nqueensolve(col+1);
				board[i][col] = 0;
			}
			}
		}
		
}
int main(){
	nqueensolve(0);
}
