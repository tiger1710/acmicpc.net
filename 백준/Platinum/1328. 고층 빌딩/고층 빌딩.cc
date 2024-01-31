#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<long long>>> dp;
long long building(int n, int left, int right) {
	if (n == 0 || left == 0 || right == 0) return 0;
	else if ((n == left && right == 1) || (n == right && left == 1)) return 1;

	long long& result = dp[n][left][right];
	if (result != -1) return result;
	result = building(n - 1, left, right)*(n - 2) + building(n - 1, left - 1, right) + building(n - 1, left, right - 1);
	result %= 1000000007;
	return result;
}

int main(void) {
	ios::sync_with_stdio(false);
	int N, L, R;
	cin >> N >> L >> R;
	dp.resize(N + 1);
	for (size_t i = 0; i < N + 1; i++) {
		dp[i].resize(L + 1);
		for (size_t k = 0; k < L + 1; k++) {
			dp[i][k].resize(R + 1, -1);
		}
	}
	
	cout << building(N, L, R) << endl;

	return 0;
}
