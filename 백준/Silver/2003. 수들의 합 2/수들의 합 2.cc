#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;

int main(void) {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	arr.push_back(0);

	for (int i = 0; i < N; i++) {
		int c; cin >> c;
		arr.push_back(arr[i] + c);
	}

	int cnt = 0;
	for (int i = 0; i <= N; i++) {
		for (int k = i + 1; k <= N; k++) {
			if (arr[k] - arr[i] == M) cnt++;
		}
	}
	cout << cnt << '\n';

	return 0;
}