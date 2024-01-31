#include <stdio.h>

int gcd(int a, int b) {
	//return a % b ? gcd(b, a%b) : b;

	while (a%b) {
		int t = a % b;
		a = b;
		b = t;
	}

	return b;
}

int A, B;

int fountain(int a, int b) {// a/b;
	while (a != 1) {
		int GCD = gcd(a, b);
		if (GCD != 1) {
			a /= GCD;
			b /= GCD;
		}
		if (a == 1) return b;
		int i = 1;
		while ((float)a / b < 1.0F / i) {
			i++;
		}
		a = (a * i - b);
		b = i * b;
	}
	return b;
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &A, &B);
		printf("%d\n", (int)fountain(A, B));
	}

	return 0;
}