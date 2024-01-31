#include <stdio.h>

int main(void) {
	int n,count=0, binggopan[5][5], bingo[12] = { 0, };//bingo 가로5+세로5+대각2
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++) {
			scanf("%d", &binggopan[k][i]);
		}
	}
	while (count<26) {
		count++;
		scanf("%d", &n);
		for (int k = 0; k < 5; k++) {
			for (int i = 0; i < 5; i++) {
				if (binggopan[k][i] == n) binggopan[k][i] = 0;
			}
		}
		for (int k = 0; k < 5; k++) {
			if (binggopan[0][k] + binggopan[1][k] + binggopan[2][k] + binggopan[3][k] + binggopan[4][k] == 0) bingo[k] = 1;
		}
		for (int i = 0; i < 5; i++) {
			if (binggopan[i][0] + binggopan[i][1] + binggopan[i][2] + binggopan[i][3] + binggopan[i][4] == 0) bingo[i+5] = 1;
		}
		if (binggopan[0][0] + binggopan[1][1] + binggopan[2][2] + binggopan[3][3] + binggopan[4][4] == 0) bingo[10] = 1;
		if (binggopan[4][0] + binggopan[3][1] + binggopan[2][2] + binggopan[1][3] + binggopan[0][4] == 0) bingo[11] = 1;
		if (bingo[0] + bingo[1] + bingo[2] + bingo[3] + bingo[4] + bingo[5] + bingo[6] + bingo[7] + bingo[8] + bingo[9] + bingo[10] + bingo[11] >= 3) break;
	}
	printf("%d\n", count);

	return 0;
}
