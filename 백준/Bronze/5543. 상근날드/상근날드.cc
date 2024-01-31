#include <stdio.h>

int main(void)
{
	int burger[3], bbest, blo, lo[2];
	for (int k = 0; k < 3; k++) {
		scanf("%d", &burger[k]);
	}
	bbest = burger[0] < burger[1] ? burger[0] : burger[1];
	bbest = bbest < burger[2] ? bbest : burger[2];
	for (int i = 0; i < 2; i++) {
		scanf("%d", &lo[i]);
	}
	blo = lo[0] < lo[1] ? lo[0] : lo[1];
	printf("%d\n", bbest + blo - 50);
	return 0;
}