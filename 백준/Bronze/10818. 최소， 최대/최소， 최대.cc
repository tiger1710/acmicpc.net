#include <stdio.h>

int main(void)
{
	int k,n;
	int max=-1000000, min=1000000;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		if (n > max) {
			max = n;
		}
		if (n < min) {
			min = n;
		}
	}
	
	printf("%d %d\n", min, max);

	return 0;
}