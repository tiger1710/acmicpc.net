#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		int n; cin >> n;
		vector<int> R(n);
		vector<int> S(n);
		vector<int> nums;
		for (int i = n; i > 0; i--) {
			nums.push_back(i);
		}
		for (int& i : R) cin >> i;

		int impossible = false;
		for (int i = n - 1; i >= 0; i--) {
			int need = n - R[i] - 1;
			if (need > nums.size()) {
				impossible = true;
				break;
			}
			S[i] = nums[need];
			n--;
			nums.erase(nums.begin() + (need));
		}

		if (not impossible) {
			for (int& i : S) cout << i << ' ';
			cout << '\n';
		}
		else cout << "IMPOSSIBLE\n";
	}

	return 0;
}