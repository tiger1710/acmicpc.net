#include <stdio.h>
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int j = 0; j < n; j++) {
		
		for (int i = 0; i <= j; i++) {
			printf("*");
		}
		for (int k = n - j - 1; k > 0; k--) {
			printf(" ");
		}
		for (int k = n - j - 1; k > 0; k--) {
			printf(" ");
		}
		for (int i = 0; i <= j; i++) {
			printf("*");
		}


		printf("\n");
	}
	for (int j = 1; j < n; j++) {
		
		for (int i = n - j; i>0; i--) {
			printf("*");
		}
		for (int k = 0; k < j; k++) {
			printf(" ");
		}
		for (int k = 0; k < j; k++) {
			printf(" ");
		}
		for (int i = n - j; i>0; i--) {
			printf("*");
		}
		

		printf("\n");
	}

	return 0;
}