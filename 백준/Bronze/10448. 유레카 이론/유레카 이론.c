#include <stdio.h>

int tri(int n) {
	return n*(n + 1) / 2;
}

int main(void) {
	int three,n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a = 1, b = 1, c = 1;
		scanf("%d", &three);
		while (1) {
			if (tri(a) > three) {
				puts("0");
				break;
			}
			while (tri(b) < three) {
				if (three < tri(a) + tri(b) + tri(c)) {
					c = 1;
					b++;
				}
				if (three == tri(a) + tri(b) + tri(c)) {
					puts("1");
					break;
				}
				else c++;
			}
			if (three == tri(a) + tri(b) + tri(c)) {
				break;
			}
			c = 1;
			b = 1;
			a++;
		}
	}
	return 0;
}