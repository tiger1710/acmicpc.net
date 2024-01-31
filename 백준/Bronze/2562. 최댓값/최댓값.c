#include <stdio.h>
int main(void) {
	int max=0,n,k;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &n);
		if (n > max) {
			max = n;
			k = i + 1;
		}
	}
	printf("%d\n%d\n", max, k);
	return 0;
}