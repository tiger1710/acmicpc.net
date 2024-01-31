#include <stdio.h>

int main(void) {
	int a, b, c,multi, num[10] = { 0, };
	scanf("%d %d %d", &a, &b, &c);
	multi = a*b*c;
	for (;multi>0; multi /= 10) {
		num[multi % 10]++;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", num[i]);
	}
	return 0;
}