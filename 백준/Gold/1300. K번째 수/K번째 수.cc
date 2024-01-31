#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	unsigned long N, k; cin >> N >> k;

	unsigned long low = 0, high = N * N;
	while (low + 1 < high) {
		unsigned long answer = ((low + high) >> 1);

		unsigned long cnt = 0;
		for (unsigned long i = 1; i <= N; i++) {
			cnt += min(answer / i, N);
		}

		if (cnt < k) low = answer;
		else high = answer;
	}

	cout << high << '\n';

	return 0;
}