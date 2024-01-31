#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, k; cin >> n >> k;
	vector<int> coin(n);
	vector<int> dp(k + 1);
	for (int& i : coin) cin >> i;

	dp[0] = 1;
	for (int c = 0; c < n; c++) {
		for (int i = 1; i <= k; i++) {
			if (i >= coin[c]) dp[i] += dp[i - coin[c]];
		}
	}
	cout << dp[k] << '\n';


	return 0;
}

