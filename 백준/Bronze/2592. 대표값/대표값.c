#include <stdio.h>

int main(void) {
	int n[10], freq[100] = {0,}, sum = 0, high,k;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &n[i]);
		sum += n[i];
	}
	for (int i = 0; i < 10; i++) {
		freq[n[i] / 10]++;
	}
	high = freq[1];
	for (k = 1; k < 100; k++) {
		if (high < freq[k]) {
			high = freq[k];
		}
	}
	for (k = 1; k < 100; k++) {
		if (high == freq[k]) {
			break;
		}
	}
	
	printf("%d\n", sum / 10);
	printf("%d\n", k*10);
	return 0;
}