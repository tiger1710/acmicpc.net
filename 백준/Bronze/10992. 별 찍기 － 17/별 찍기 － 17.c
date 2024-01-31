#include <stdio.h>
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main(void) {
	// your code goes here
	int n , i, q, k;
	scanf("%d", &n);
	for (i = 0; i < 2*n-1; i+=2) {
		for (q = 2*n-1-i-1;q>0;q-=2) {
			printf(" ");
		}
		for (k = 0; k <= i; k++) {
			if (i == 2 * n - 2) {
				for (int j = 0;j<i+1; j++) {
					printf("*");
				}
				break;
			}
			if (k>0 && k<i) {
				printf(" ");
				continue;
			}
			printf("*");
		}
		puts("");
	}

	return 0;
}