#include <stdio.h>

int main(void) {
	int testCase;
	scanf("%d", &testCase);

	int tc;
	for (tc = 0; tc < testCase; tc++) {
		int H, W, N;
		scanf("%d%d%d", &H, &W, &N);
		if (N%H) {
			printf("%d%02d\n", N % H, N / H + 1);
		}
		else {
			printf("%d%02d\n", H, N / H);
		}
	}

	return 0;
}