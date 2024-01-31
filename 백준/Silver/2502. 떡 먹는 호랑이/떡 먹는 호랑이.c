#include <stdio.h>

int adder(int a, int b,int cnt) {
	return cnt ? adder(b, a + b, cnt - 1) : a + b;
}

int main(void) {
	int Dduck,count,A=1,B=1;
	scanf("%d %d", &count, &Dduck);
	while (Dduck != adder(A, B, count - 3)) {
		B++;
		if (Dduck < adder(A, B, count - 3)) {
			B = 1;
			A++;
		}
	}
	printf("%d\n%d\n", A, B);
	return 0;
}