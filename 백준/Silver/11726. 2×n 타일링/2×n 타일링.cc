#include <iostream>
#include <vector>
using namespace std;

vector<unsigned> dp;
unsigned n;
int main(void) {
	ios::sync_with_stdio(false);
	cin >> n;
	dp.push_back(0);
	dp.push_back(1);
	for (size_t i = 2; i <= n + 1; i++) {
		dp.push_back((dp[i - 2] + dp[i - 1]) % 10007);
	}
	cout << dp[n + 1] << endl;

	return 0;
}