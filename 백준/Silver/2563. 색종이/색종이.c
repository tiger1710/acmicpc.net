#include <stdio.h>

int main(void) 
{
	int n, dohwaji[101][101] = { 0 },square=0;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		for (int k = x;k < x + 10;k++) {
			for (int j = y;j < y + 10;j++) {
				dohwaji[j][k]++;
			}
		}
	}
	for (int i = 0;i < 100;i++) {
		for (int k = 0;k < 100;k++) {
			if (dohwaji[i][k] > 0) {
				square++;
			}	
		}
	}
	printf("%d\n", square);
	return 0;
}