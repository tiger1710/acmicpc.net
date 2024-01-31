#include <iostream>
#include <vector>
#include <limits>
using namespace std;


int main(void) {
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<int> lesson; lesson.resize(N);
	int part; cin >> part;
	vector<int> partition; partition.resize(part, 0);
	for (int i = 0; i < N; i++) {
		cin >> lesson[i];
	}

	int low = 0, high = 0x7fffffff;

	while (low + 1 < high) {
		int answer = ((low + high) >> 1);
		size_t index = 0;
		for (int i = 0; i < part; i++) {
			while (index < N && partition[i] + lesson[index] <= answer) partition[i] += lesson[index++];
		}
		if (index < N) low = answer;
		else high = answer;
		for (int i = 0; i < part; i++) {
			partition[i] = 0;
		}
	}

	cout << low + 1<< endl;

	return 0;
}