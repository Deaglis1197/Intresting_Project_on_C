#include <stdio.h>
#define X 5
int main() {
	int d[X][X];
	for (int i = 0; i < X-1; i++) {
		
		for (int j = 0; j <= i; j++) {
			if (j == 0 || i == j) {
				d[i][j] = 1;
			}
			else {
				d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
			}
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}

	getch();
}
