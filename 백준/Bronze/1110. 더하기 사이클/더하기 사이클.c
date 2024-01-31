#include <stdio.h>


int main(void) {
	int n,m, count = 0, sum = 0;
	scanf("%d", &n);
	m = n;
	do {
		sum = (m / 10) + (m % 10);
		m = (m % 10) * 10 + sum % 10;
		count++;
	} while (n != m);
	printf("%d\n", count);

	return 0;
}