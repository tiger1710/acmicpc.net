#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> dp;

long long cnt(unsigned size, int last) {
	if (last < 0 || last > 9) return 0;
	if (size == 0) return dp[size][last] = last ? 1 : 0;
	if (dp[size][last]) return dp[size][last];
	long long ans = cnt(size - 1, last - 1) + cnt(size - 1, last + 1);
	return dp[size][last] = ans % 1000000000;
}

int main(void) {
	ios::sync_with_stdio(false);
	unsigned n;
	cin >> n;
	if (n < 1) {
		cout << '0' << endl;
		return 0;
	}
	dp.resize(n);
	for (size_t i = 0; i < n; i++) {
		dp[i].resize(10);
	}

	long long ans = 0;
	for (size_t i = 0; i < 10; i++) {
		ans += cnt(n - 1, i);
	}
	cout << ans % 1000000000 << endl;


	return 0;
}

//#include <iostream>
//using namespace std;
//long long d[101][10];
//long long mod = 1000000000;
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= 9; i++) {
//		d[1][i] = 1;
//	}
//	for (int i = 2; i <= n; i++) {
//		for (int j = 0; j <= 9; j++) {
//			d[i][j] = 0;
//			if (j - 1 >= 0) {
//				d[i][j] += d[i - 1][j - 1];
//			}
//			if (j + 1 <= 9) {
//				d[i][j] += d[i - 1][j + 1];
//			}
//			d[i][j] %= mod;
//		}
//	}
//	long long ans = 0;
//	for (int i = 0; i <= 9; i++) {
//		ans += d[n][i];
//	}
//	ans %= mod;
//	cout << ans << '\n';
//	return 0;
//}