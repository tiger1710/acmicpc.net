#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	sort(v.begin(), v.end());
	for (int ans = 10000; ans >= 0; ans--) {
		auto it = lower_bound(v.begin(), v.end(), ans);
		if (ans <= v.end() - it) {
			cout << ans << '\n';
			return 0;
		}
	}

	return 0;
}