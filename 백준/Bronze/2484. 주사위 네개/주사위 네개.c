#include <stdio.h>
int bestscore=0;
int best(int a,int b) {
	return a < b ? b : a;
}

void cubing(int cube[], int g) {
	int  i=g, k;
	for (i; i < 6; i++) {
		if (cube[i] == 0) continue;
		else if (cube[i] == 4) {
			bestscore = best(bestscore, 50000 + (i + 1) * 5000);
			break;
		}
		else if (cube[i] == 3) {
			bestscore = best(bestscore, 10000 + (i + 1) * 1000);
			break;
		}
		else if (cube[i] == 2) {
			for (k = i + 1; k < 6; k++) {
				if (cube[k] == 2) {
					bestscore = best(bestscore, 2000 + (i + 1) * 500 + (k + 1) * 500);
					break;
				}
			}
			if (k == 6) {
				bestscore = best(bestscore, 1000 + (i + 1) * 100);
				break;
			}
			else break;
		}
		else {
			if (g == 3) {
				for (k = 5; k >= 0; k--) {
					if (cube[k]>0) {
						bestscore = best(bestscore, (k + 1) * 100);
						break;
					}
				}
			}
			cubing(cube,g+1);
		}
	}
}
int main(void)
{
	int i, i__ = 0, n;
	scanf("%d", &n);
	while (i__ < n) {
		i__++;
		int cube[6] = { 0, };
		for (i = 0; i < 4; i++) {
			int a;
			scanf("%d", &a);
			cube[a - 1]++;
		}
		cubing(cube,0);
	}
	printf("%d\n", bestscore);


	return 0;
}