#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
unsigned short T, W;
vector<unsigned> time;
vector<vector<short>> dp;

short jadu(short t, short w, short pos) {
	if (t == T) return 0;
	if (w > ::W) return 0;
	short& cnt = dp[t][w];
	if (cnt != -1) return dp[t][w];

	cnt = max(jadu(t, w + 1, !pos), jadu(t + 1, w, pos));

	if (time[t] == pos) return ++cnt;
	else return cnt;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin >> ::T >> ::W;
	dp.resize(::T + 5);

	for (int i = 0; i < ::T + 5; i++) {
		dp[i].resize(::W + 5, -1);
	}

	for (int i = 0; i < T; i++) {
		short n;
		cin >> n;
		time.push_back(n - 1);
	}

	cout << jadu(0, 0, 0) << endl;

	return 0;
}