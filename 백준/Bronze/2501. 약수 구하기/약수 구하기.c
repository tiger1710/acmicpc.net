#include <stdio.h>

int main(void) {
	int i, n, m, k, count = 0;
	scanf("%d %d", &n, &k);
	for (i = 1; i / 2 < n; i++) {
		if (n%i == 0) {
			m = i;
			count++;
			if (k == count) {
				break;
			}
		}
	}
	if (count < k) {
		puts("0");
	}
	else {
		printf("%d\n", m);
	}
	return 0;
}