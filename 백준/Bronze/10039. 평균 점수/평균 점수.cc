#include <stdio.h>

int main(void)
{
	int score=0,s=0;
	for (int k = 0; k < 5; k++) {
		scanf("%d", &score);
		if (score < 40) {
			score = 40;
		}
		s += score;
	}
	printf("%d", s / 5);

	return 0;
}