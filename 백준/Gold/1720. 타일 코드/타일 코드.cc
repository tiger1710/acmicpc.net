#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int tile(int n) {
	if (n < 2) return 1;
	if (dp[n]) return dp[n];
	return tile(n - 1) + (tile(n - 2) << 1);
}

int main(void) {
	ios::sync_with_stdio(false);
	int N; cin >> N;
	dp.resize(N + 1);

	int same = tile((N >> 1) + !(N & 1));
	cout << tile(N) - ((tile(N) - same) >> 1) << endl;

	return 0;
}