//http://wookje.dance/2017/09/27/boj-13269-%EC%8C%93%EA%B8%B0%EB%82%98%EB%AC%B4/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	vector<int> arr(n);
	for (int& i : arr) cin >> i;
	sort(arr.begin(), arr.end());

	int s = 0;
	for (int i = 0; i < n; i++) {
		s += arr[i];
		if (s < (i + 1) * i / 2) {
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << (s not_eq n * (n - 1) / 2 ? -1 : 1) << '\n';

	return 0;
}