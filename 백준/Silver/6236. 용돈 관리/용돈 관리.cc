#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<int> money;
vector<int> partition;

int main(void) {
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	
	money.resize(N);
	partition.resize(M);
	for (auto& i : money) {
		cin >> i;
	}

	int low = 0, high = numeric_limits<int>::max();
	while (low + 1 < high) {
		long long answer = ((low + high) >> 1);

		size_t index = 0;
		for (auto& i : partition) {
			while (index < N && i + money[index] <= answer) i += money[index++];
		}

		if (index < N) low = answer;
		else high = answer;

		for (auto& i : partition) i = 0;
	}

	cout << high << '\n';

	return 0;
}