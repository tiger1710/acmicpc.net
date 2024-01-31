#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

vector<long> house;
int main(void) {
	ios::sync_with_stdio(false);
	int N, C; cin >> N >> C;
	house.resize(N);
	for (auto& i : house) {
		cin >> i;
	}
	sort(house.begin(),house.end());

	long low = 0, high = numeric_limits<long>::max();
	while (low + 1 < high) {
		long answer = ((low + high) >> 1);
		
		long cnt = 1, cur = 0;
		for (int i = 1; i < N; i++) {
			if (house[i] - house[cur] >= answer) {
				cnt++;
				cur = i;
			}
		}

		if (cnt < C) high = answer;
		else low = answer;
	}

	cout << low << endl;


	return 0;
}