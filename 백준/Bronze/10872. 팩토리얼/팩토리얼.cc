#include <stdio.h>

int main(void)
{
	int n,s=1;
	scanf("%d", &n);
	for (int i = 1;i<=n; i++) {
		s *= i;
	}
	printf("%d", s);
	return 0;
}