#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pos;

int main(void) {
	ios::sync_with_stdio(false);
	int N, M, L; cin >> N >> M >> L;
	pos.resize(N);
	for (auto& i : pos) {
		cin >> i;
	}
	sort(pos.begin(), pos.end());
	pos.push_back(L);

	int low = 0, high = L;
	while (low + 1 < high) {
		int answer = ((low + high) >> 1);

		int cur = 0, cnt = 0;
		for (const auto& i : pos) {
			cnt += (i - cur - 1) / answer;
			cur = i;
		}

		if (cnt > M) low = answer;
		else high = answer;
	}
	cout << high << '\n';

	return 0;
}