#include <stdio.h>

int main(void) {
	int n,sum=0,score=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int ox;
		scanf("%d", &ox);
		if (ox == 1) {
			score++;
		}
		else {
			score = 0;
		}
		sum += score;
	}
	printf("%d\n", sum);
	return 0;
}