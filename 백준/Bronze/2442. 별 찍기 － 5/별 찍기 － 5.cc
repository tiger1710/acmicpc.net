#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
		for (int k = 0; k < 2*n; k += 2) {
			for (int j = 2*n-2; j > k; j-=2) {
				printf(" ");
			}
			for (int i = 0; i <= k; i++) {
				printf("*");
			}
			printf("\n");
		}
	return 0;
}