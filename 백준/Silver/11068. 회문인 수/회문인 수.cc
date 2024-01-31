#include <iostream>
#include <vector>
using namespace std;

void p(vector<int>& isP, int n, const int& B) {
	if (not n) return;
	p(isP, n / B, B);
	isP.push_back(n % B);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		int n; cin >> n;
		vector<int> isP;
		bool flag = true;
		for (int i = 2; i <= 64; i++) {
			p(isP, n, i);
			flag = true;
			for (int s = 0, t = isP.size() - 1; s < t; s++, t--) {
				if (isP[s] not_eq isP[t]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << 1 << '\n';
				break;
			}
			isP.clear();
		}
		if (not flag) cout << 0 << '\n';
	}

	return 0;
}
