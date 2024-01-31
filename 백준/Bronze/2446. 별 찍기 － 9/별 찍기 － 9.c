#include <stdio.h>
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int j = 0; j < 2 * n - 1; j += 2) {
		for (int i = 0; i < j; i += 2) {
			printf(" ");
		}
		if (j == 2 * n - 1 - 1) {
			break;
		}
		for (int k = 2*n-1-j; k > 0; k--) {
			printf("*");
		}
		
		printf("\n");
	}
	for (int j = 0; j < 2*n-1; j+=2) {
		for (int i = 2*n-1-j-1; i > 0; i-=2) {
			if (j == 0) {
				break;
			}
			printf(" ");
		}
		for (int k = 0; k <= j; k++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
