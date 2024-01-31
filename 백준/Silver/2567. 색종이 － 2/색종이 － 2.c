#include <stdio.h>

int main(void) 
{
	int i, j, k, n, dohwaji[101][101] = { 0 },square=0; int x, y;
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		scanf("%d%d", &x, &y);
		for (k = x;k < x + 10;k++) {
			for (j = y;j < y + 10;j++) {
				dohwaji[j][k]++;
			}
		}
	}
	for (i = 0;i < 100;i++) {
		for (k = 0;k < 100;k++) {
			if (dohwaji[i][k] > 0) {
				if (dohwaji[i - 1][k]==0) {
					square++;
				}
				if (dohwaji[i + 1][k]==0) {
					square++;
				}
				if (dohwaji[i][k - 1]==0) {
					square++;
				}
				if (dohwaji[i][k + 1]==0) {
					square++;
				}
			}
		}
	}
	printf("%d\n", square);
	return 0;
}