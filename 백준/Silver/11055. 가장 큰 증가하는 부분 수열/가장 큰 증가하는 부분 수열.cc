#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> dp;
int N;

int main(void) {
	ios::sync_with_stdio(false);
	cin >> N;
	dp.resize(N + 5);
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		arr.push_back(move(n));
	}

	for (int i = 0; i < N; i++) {
		dp[i] = arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int k = i + 1; k < N; k++) {
			if (arr[i] < arr[k] && dp[k] < dp[i] + arr[k]) {
				dp[k] = dp[i] + arr[k];
			}
		}
	}
	
	int result = 0;
	for (int i = 0; i < N; i++) {
		result = max(result, dp[i]);
	}

	cout << result << endl;

	return 0;
}