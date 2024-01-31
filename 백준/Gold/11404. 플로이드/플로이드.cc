#include <iostream>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int, int> pii;
constexpr int INF = numeric_limits<int>::max() >> 1;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<vector<int>> cost(n,vector<int>(n, INF));
	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		cost[a - 1][b - 1] = min(cost[a - 1][b - 1], c);
	}
	for (int i = 0; i < n; i++) cost[i][i] = 0;

	for (int bypass = 0; bypass < n; bypass++) {
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n; k++) {
				cost[i][k] = min(cost[i][k], cost[i][bypass] + cost[bypass][k]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cout << (cost[i][k] not_eq INF ? cost[i][k] : 0) << ' ';
		}
		cout << '\n';
	}


	return 0;
}