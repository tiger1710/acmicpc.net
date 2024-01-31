#include <stdio.h>

int main(void)
{
	int n, cup[3] = { 1,0,0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int change_1, change_2,t;
		scanf("%d %d", &change_1, &change_2);
		t = cup[change_1-1];
		cup[change_1 - 1] = cup[change_2 - 1];
		cup[change_2-1] = t;
	}
	if (!cup[0] && !cup[1] && !cup[2]) {
		puts("-1");
	}
	else {
		for (int i = 0; i < 3; i++) {
			if (cup[i]) {
				printf("%d\n",i+1);
				break;
			}
		}
	}

	return 0;
}