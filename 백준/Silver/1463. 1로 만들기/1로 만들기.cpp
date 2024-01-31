#include <iostream>
#define MAX 1000005

using namespace std;

int dfs(int cur) {
	static int dp[MAX];
	if (cur == 1) return dp[1] = 0;
	if (dp[cur]) return dp[cur];
	dp[cur] = dfs(cur - 1) + 1;
	if (!(cur % 3)) dp[cur] = dp[cur / 3] + 1 < dp[cur] ? dp[cur / 3] + 1 : dp[cur];
	if (!(cur % 2)) dp[cur] = dp[cur / 2] + 1 < dp[cur] ? dp[cur / 2] + 1 : dp[cur];

	return dp[cur];
}

int main(void) {
	int X;
	cin >> X;
	cout << dfs(X) << endl;

	return 0;
}
