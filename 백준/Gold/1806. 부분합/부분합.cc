#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, S; cin >> N >> S;
	vector<long long> pSum;
	pSum.push_back(0);
	for (int i = 0, e; i < N; i++) {
		cin >> e; pSum.push_back(pSum[i] + e);
	}

	int start = 0, end = 1, minLen = 100001, len = 1;
	while (end <= N) {
		long long partial = pSum[end] - pSum[start];
		if (partial >= S) {
			minLen = minLen > len ? len : minLen;
			start++, len--;
		}
		else {
			end++, len++;
		}
	}

	if (minLen not_eq 100001) cout << minLen << '\n';
	else cout << 0 << '\n';

	return 0;
}