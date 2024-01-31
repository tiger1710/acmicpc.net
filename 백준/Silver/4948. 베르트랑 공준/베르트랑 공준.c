#include <stdio.h>

int main(void) {

	int i, k, n;
	while (1) {
		int count = 0;
		scanf("%d", &n);
		if (n == 0) break;
		for (i = n+1; i <= 2 * n; i++) {
			int switch_n = 1;
			for (k = 2; k*k <= i; k++) {
				if (i%k == 0) {
					switch_n = 0;
					break;
				}
			}
			if (switch_n == 1 && i != 0) {
				count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}