#include <stdio.h>

int main(void)
{
	int people = 0,in,out,i,best=0;

	for (i = 0; i < 4; i++) {
		scanf("%d %d", &out, &in);
		people -= out;
		people += in;
		best = best < people ? people : best;
	}
	printf("%d\n", best);

	return 0;
}