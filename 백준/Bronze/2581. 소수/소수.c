#include <stdio.h>

int main(void) {
	int m,n,sum=0,min=10001;
	scanf("%d %d", &m,&n);
	for (int k = m; k <= n; k++) {
		int prime_num = 1;
		for (int i = 2; i*i <= k; i++) {
			if (k%i == 0 || k==0||k==1 ) {
				prime_num = 0;
				break;
			}
		}
		if (prime_num && k!=0 && k!=1) {
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