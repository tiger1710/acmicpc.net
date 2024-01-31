#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		int m, n; cin >> m >> n;
		cout << 1 << '\n';
		if (m & 1 and n & 1) {
			for (int i = 0; i < m; i++) {
				for (int k = 0; k < n - 1; k++) {
					cout << '(' << i << ',' << k << ')' << '\n';
				}
				i++;
				if (i >= m) break;
				for (int k = n - 2; k >= 0; k--) {
					cout << '(' << i << ',' << k << ')' << '\n';
				}
			}
			for (int i = m - 1; i >= 0; i--) {
					cout << '(' << i << ',' << n - 1 << ')' << '\n';
			}
		}
		else if (m & 1) {
			for (int i = 0; i < n; i++) {
				for (int k = 0; k < m; k++) {
					cout << '(' << k << ',' << i << ')' << '\n';
				}
				i++;
				for (int k = m - 1; k >= 0; k--) {
					cout << '(' << k << ',' << i << ')' << '\n';
				}
			}
		}
		else {
			for (int i = 0; i < m; i++) {
				for (int k = 0; k < n; k++) {
					cout << '(' << i << ',' << k << ')' << '\n';
				}
				i++;
				for (int k = n - 1; k >= 0; k--) {
					cout << '(' << i << ',' << k << ')' << '\n';
				}
			}
		}
	}


	return 0;
}