#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int k = n; k > 0; k--) {
		for (int j = 0; j < n-k; j++) {
			printf(" ");
		}
		for (int i = k; i > 0; i--) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}