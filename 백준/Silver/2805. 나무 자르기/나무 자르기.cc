#include <iostream>
#include <vector>
using namespace std;
vector<int> tree;
int main(void) {
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	tree.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
	}

	int low = 0, high = 1000000000;
	while (low + 1 < high) {
		int mid = ((low + high) >> 1);

		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if (tree[i] > mid) sum += (tree[i] - mid);
		}

		if (sum < M) high = mid;
		else low = mid;
	}
	cout << low << endl;

	return 0;
}