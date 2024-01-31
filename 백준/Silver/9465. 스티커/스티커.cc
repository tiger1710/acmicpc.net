#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
enum pos {
	up, down, nothing
};
vector<vector<int>> score;
vector<vector<int>> dp;

/*int sticker(int col, int pos) {
	if (col == n) return 0;
	if (dp[col][pos] >= 0) return dp[col][pos];
	int result = sticker(col + 1, nothing);
	if (pos != up) {
		int temp = sticker(col + 1, up) + score[up][col];
		result = result < temp ? temp : result;
	}
	if (pos != down) {
		int temp = sticker(col + 1, down) + score[down][col];
		result = result < temp ? temp : result;
	}
	return dp[col][pos] = result;
}*/

int main(void) {
	std::ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		score.resize(2);
		cin >> n;
		dp.resize(n + 1);
		for (int i = 0; i < 2; i++) {
			score[i].resize(n);
			for (int k = 0; k < n; k++) {
				cin >> score[i][k];
				dp[k].resize(3, 0);
			}
		}
		dp[n].resize(3, 0);
		//cout << sticker(0, nothing) << endl;
		for (int i = 0; i < n; i++) {
			dp[i + 1][nothing] = max(dp[i][nothing], max(dp[i][up], dp[i][down]));
			dp[i + 1][up] = max(dp[i][nothing], dp[i][down]) + score[up][i];
			dp[i + 1][down] = max(dp[i][nothing], dp[i][up]) + score[down][i];
		}
		cout << max(dp[n][nothing], max(dp[n][up], dp[n][down])) << endl;
		score.clear();
		dp.clear();
	}

	return 0;
}