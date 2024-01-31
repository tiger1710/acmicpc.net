#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	vector<vector<int>> t(n);
	vector<vector<int>> dp(n);
	for (int i = 0; i < n; i++) {
		for (int k = 0, v; k <= i; k++) {
			cin >> v; t[i].push_back(v);
		}
		dp[i].resize(i + 1);
	}

	dp[0][0] = t[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = t[i][0] + dp[i - 1][0];
		for (int k = 1; k < i; k++) {
			dp[i][k] = t[i][k] + max(dp[i - 1][k - 1], dp[i - 1][k]);
		}
		dp[i][i] = t[i][i] + dp[i - 1][i - 1];
	}

	int m = dp[n - 1][0];
	for (int i = 1; i < n; i++) {
		m = max(m, dp[n - 1][i]);
	}

	cout << m << '\n';

	return 0;
}