#include <stdio.h>

int main(void)
{
	int n, i, k,j;
	scanf("%d", &n);
	for (j = 0; j < n; j++) {
		for (int k = 1;k<n-j; k++) {
			printf(" ");
		}
		for (int i = 0; i <= j; i++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}