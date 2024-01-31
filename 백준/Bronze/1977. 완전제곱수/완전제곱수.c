#include <stdio.h>

int main(void) {

	int m, n, sum = 0, min = 10001,i,k;
	scanf("%d %d", &m, &n);
	for (k = m; k <= n; k++) {
		int square = 0;
		for (i = 1; i*i <= k; i++) {
			if (i*i==k) {
				square = 1;
				break;
			}
		}
		if (i*i==k) {
			sum += k;
			min = min > k ? k : min;
		}
	}
	if (sum == 0) {
		puts("-1");
	}
	else {
		printf("%d\n%d\n", sum, min);
	}

	return 0;
}