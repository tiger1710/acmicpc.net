#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
enum Color {RED, GREEN, BLUE};

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N; cin >> N;
	vector<vector<int>> cost(N, vector<int>(3));
	vector<vector<int>> dp(N, vector<int>(3));

	for (auto& i : cost) {
		for (auto& k : i) {
			cin >> k;
		}
	}

	dp[0][RED] = cost[0][RED];
	dp[0][GREEN] = cost[0][GREEN];
	dp[0][BLUE] = cost[0][BLUE];

	for (int i = 1; i < N; i++) {
		dp[i][RED] = cost[i][RED] + min(dp[i - 1][GREEN], dp[i - 1][BLUE]);
		dp[i][GREEN] = cost[i][GREEN] + min(dp[i - 1][RED], dp[i - 1][BLUE]);
		dp[i][BLUE] = cost[i][BLUE] + min(dp[i - 1][RED], dp[i - 1][GREEN]);
	}

	int minCost = min(dp[N - 1][RED], min(dp[N - 1][GREEN], dp[N - 1][BLUE]));
	cout << minCost << '\n';

	return 0;
}