#include <iostream>
#include <limits>
#include <vector>
using namespace std;

vector<int> line;

int main(void) {
	ios::sync_with_stdio(false);
	int K, N; cin >> K >> N;
	
	line.resize(K);
	for (auto& i : line) {
		cin >> i;
	}

	long long low = 0, high = numeric_limits<long long>::max();
	while (low + 1 < high) {
		long long answer = ((low + high) >> 1);

		long long num = 0;
		for (auto& i : line) num += (i / answer);

		if (num < N) high = answer;
		else low = answer;
	}

	cout << low << endl;

	return 0;
}