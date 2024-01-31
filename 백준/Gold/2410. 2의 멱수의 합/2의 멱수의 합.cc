#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> dp;

int main(void) {
	ios::sync_with_stdio(false);
    int N;
	cin >> N;
	dp.resize(N + 1);
	
	dp[0] = 1LL;
	for (int i = 0; (1 << i) <= N; i++) {
		int num = (1 << i);
		for (int k = num; k <= N; k++) {
			dp[k] += dp[k - num];
			dp[k] %= 1000000000;
		}
	}
	cout << dp[N] << endl;

	return 0;
}