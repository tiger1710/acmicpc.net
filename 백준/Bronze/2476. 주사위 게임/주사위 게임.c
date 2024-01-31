#include <stdio.h>
int best(int a, int b, int c) {
	int A;
	A = a > b ? a : b;
	A = c > A ? c : A;
	return A;
}

int main(void)
{
	int bestscore=0,n,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int a;
		int cube[3];
		scanf("%d %d %d", &cube[0], &cube[1], &cube[2]);
		if (cube[0] == cube[1] && cube[1] == cube[2]) {
			bestscore = bestscore < cube[0] * 1000 + 10000 ? cube[0] * 1000 + 10000 : bestscore;
		}
		else if (cube[0] != cube[1] && cube[1] != cube[2] && cube[0]!=cube[2]) {
			a = best(cube[0], cube[1], cube[2]);
			bestscore = bestscore < a * 100 ? a * 100 : bestscore;
		}
		else {
			if (cube[0] == cube[1]) {
				a = cube[0];
				bestscore = bestscore < a * 100 + 1000 ? a * 100 + 1000 : bestscore;
			}
			else if (cube[1] == cube[2]) {
				a = cube[1];
				bestscore = bestscore < a * 100 + 1000 ? a * 100 + 1000 : bestscore;
			}
			else {
				a = cube[0];
				bestscore = bestscore < a * 100 + 1000 ? a * 100 + 1000 : bestscore;
			}
		}
	}
	printf("%d\n", bestscore);


	return 0;
}