#include <stdio.h>
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main(void)
{
	int k,n,m;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &n, &m);
		printf("%d\n", n*m / gcd(n, m));
	}
	return 0;
}