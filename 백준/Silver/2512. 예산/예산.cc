#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> states;
int main(void) {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	states.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> states[i];
	}
	int limit; cin >> limit;

	int total = 0, ma = 0;
	for (int i = 0; i < N; i++) {
		total += states[i];
		ma = max(ma, states[i]);
	}
	if (total <= limit) {
		cout << ma << endl;
		return 0;
	}

	int low = 1, high = 1000000001;
	while (low + 1 < high) {
		int answer = ((low + high) >> 1);

		total = 0;
		for (int i = 0; i < N; i++) {
			if (states[i] > answer) total += answer;
			else total += states[i];
		}

		if (limit < total) {
			high = answer;
		}
		else {
			low = answer;
		}
	}

	cout << low << endl;

	return 0;
}