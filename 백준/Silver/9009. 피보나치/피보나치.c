#include <stdio.h>
#define MAX 46

int dp[MAX];
int want, cnt, sum[MAX];

int fibbo(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (!dp[n]) return dp[n] = fibbo(n - 1) + fibbo(n - 2);
	else return dp[n];
}

void find(int n) {
	int SUM = 0;
	if (n <= 1) {
		sum[cnt++] = n;
		return;
	}
	sum[cnt++] = dp[n];
	for (int i = 0; i < cnt; i++) {
		SUM += sum[i];
	}
	if (want == SUM) {
		return;
	}
	else if (want < SUM) {
		cnt--;
		find(n - 1);
	}
	else {
		find(n - 1);
	}
}

int main(void) {
	fibbo(MAX);
	int testCase;
	scanf("%d", &testCase);
	for (int tc = 0; tc < testCase; tc++) {
		scanf("%d", &want);
		for (int i = 0; i < MAX; i++) {
			if (dp[i] > want) {
				find(i - 1);
				break;
			}
		}
		for (int i = cnt - 1; i >= 0; i--) {
			printf("%d ", sum[i]);
		}
		puts("");
		cnt = 0;
	}
	return 0;
}