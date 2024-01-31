#include <stdio.h>

int main(void)
{
	int n, x, size[10000];
	scanf("%d %d", &n, &x);
	for (int k = 0; k < n; k++) {
		scanf("%d", &size[k]);
	}
	for (int i = 0; i < n; i++) {
		if (size[i] < x) {
			printf("%d ", size[i]);
		}
	}
	return 0;
}