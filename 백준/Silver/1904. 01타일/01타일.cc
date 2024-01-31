#include <iostream>
using namespace std;

int dp[1000000];
int tile(int n) {
	if (n < 3) return n;
	if (dp[n]) return dp[n];
	int result = tile(n - 1) + tile(n - 2);
	return dp[n] = result % 15746;
}

int main(void) {
	int n;
	cin >> n;
	cout << tile(n) << endl;

	return 0;
}