#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<vector<int>> dp;
vector<vector<bool>> checked;

int maxSum(int numbers, int intervals) {
	if (intervals == 0) return 0;
	if (numbers <= 0) return numeric_limits<int>::min() / 2;
	if (checked[numbers][intervals]) return dp[numbers][intervals];
	checked[numbers][intervals] = true;
	int& ans = dp[numbers][intervals];
	ans = maxSum(numbers - 1, intervals);
	int sum = 0;
	for (size_t i = numbers; i > 0; i--) {
		sum += arr[i - 1];
		ans = max(ans, maxSum(i - 2, intervals - 1) + sum);
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	size_t N, intervals;
	cin >> N;
	cin >> intervals;
	for (size_t i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	dp.resize(N + 1);
	checked.resize(N + 1);
	for (size_t i = 0; i < N + 1; i++) {
		dp[i].resize(N + 1);
		checked[i].resize(N + 1);
	}

	cout << maxSum(N, intervals) << endl;

	return 0;
}