#include <stdio.h>

int main(void) {
	int m, n;
	scanf("%d %d", &m, &n);
	printf("%d\n", m*(n % 10));
	printf("%d\n", m*(n % 100 - n % 10)/10);
	printf("%d\n", m*(n / 100));
	printf("%d\n", m*(n % 10) + m*(n % 100 - n % 10) + 100 * m*(n / 100));
	return 0;
}