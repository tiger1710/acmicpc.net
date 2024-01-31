#include <stdio.h>

int main(void)
{
	int m,n;
	scanf("%d", &m);
	n = m;
	for (int i = 2; i <= n; i++) {
		if (n%i==0) {
			n /= i;
			printf("%d\n", i);
			i--;
			continue;
		}
	}
	return 0;
}