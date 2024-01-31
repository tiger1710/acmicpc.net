#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> change;
vector<vector<bool>> dp;

int main(void) {
	ios::sync_with_stdio(false);

	int N, S, M;
	cin >> N >> S >> M;
	dp.resize(N + 1);
	for (int i = 0; i < N + 1; i++) dp[i].resize(M + 1);;

	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		change.push_back(n);
	}

	dp[0][S] = true;
	for (int i = 1; i <= N; i++) {
		for (int k = 0; k <= M; k++) {
			if (dp[i - 1][k]) {
				if (k - change[i - 1] >= 0) dp[i][k - change[i - 1]] = true;
				if (k + change[i - 1] <= M) dp[i][k + change[i - 1]] = true;
			}
		}
	}

	int ans = -1;

	for (int i = M; i >= 0; i--) {
		if (dp[N][i]) {
			ans = i;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}