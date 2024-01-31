#include <iostream>
using namespace std;

typedef pair<int, int> pii;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		int M, N; cin >> M >> N;
		int x, y; cin >> x >> y;

		int s = (x % N) ? (x % N) : N;
		pii cur = { s, s };

		int na = cur.second;
		int cnt = 0;
		do {
			if (cur.second == y) break;
			cur.second += M;
			cur.second = (cur.second % N) ? (cur.second % N) : N;
			cnt++;
		} while (cur.second not_eq na);

		if (cur.second == y) cout << x + cnt * M << '\n';
		else cout << -1 << '\n';
	}

}