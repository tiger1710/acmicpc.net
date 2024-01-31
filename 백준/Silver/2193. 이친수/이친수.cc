#include <iostream>
#include <vector>
using namespace std;
int n;
int cnt;
vector<vector<long long int>> dp;
unsigned long long int pinary(int N, int digit) {
	if (N < 0) {
		if (digit != 0) return 1;
		else return 0;
	}
	if (dp[N][digit] != -1) return dp[N][digit];
	unsigned long long int cnt = 0;
	if (digit != 0) cnt += pinary(N - 1, 0);
	else {
		cnt += pinary(N - 1, 1) + pinary(N - 1, 0);
	}
	return dp[N][digit] = cnt;
}

int main(void) {
	cin >> n;
	dp.resize(n);
	for (int i = 0; i < n; i++) {
		dp[i].resize(2, -1);
	}
	cout << pinary(n - 1, 0) << endl;

	return 0;
}