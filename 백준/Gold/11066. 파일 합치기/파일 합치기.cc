#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<vector<int>> dp;
vector<int> file;
int merge(int from, int to) {
	if (from >= to) return 0;
	if (dp[from][to]) return dp[from][to];
	
	int& ans = dp[from][to] = numeric_limits<int>::max();
	for (int i = from; i < to; i++) {
		ans = min(ans, merge(from, i) + merge(i + 1, to));
	}
	return ans += file[to] - file[from - 1];
}


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		int k; cin >> k;
		dp.resize(k + 1); for (auto& i : dp) i.resize(k + 1);
		file.push_back(0);
		for (int i = 0, v; i < k; i++) {
			cin >> v;
			file.push_back(v + file[i]);
		}
		cout << merge(1, k) << '\n';
		file.clear(); dp.clear();
	}



	return 0;
}
