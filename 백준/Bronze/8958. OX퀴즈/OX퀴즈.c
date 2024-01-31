#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char ox[80]; int sum = 0, score=0;
		scanf("%s", &ox);
		for (int k = 0; ox[k]!=NULL; k++) {
			if (ox[k] == 'O') {
				score++;
			}
			else {
				score = 0;
			}
			sum += score;
		}
		printf("%d\n", sum);
	}
	return 0;
}