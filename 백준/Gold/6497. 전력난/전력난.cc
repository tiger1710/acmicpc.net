#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> dist;

int parent[200000];
dist edge[200001];
int find(int node) {
	if (parent[node] not_eq -1) return parent[node] = find(parent[node]);
	return node;
}

void unite(int u, int v) {
	parent[find(u)] = find(v);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	while (true) {
		int m, n; cin >> m >> n;
		if (not m and not n) break;
		
		for (int i = 0; i < m; i++) {
			parent[i] = -1;
		}

		long long sum = 0;
		for (int i = 0; i < n; i++) {
			int x, y, z; cin >> x >> y >> z;
			edge[i] = dist(z, pii(x, y));
			sum += z;
		}
		sort(edge, edge + n);

		long long k = 0;
		int cnt = 0;
		for (int i = 0; i < n and cnt < m - 1; i++) {
			int u = edge[i].second.first;
			int v = edge[i].second.second;
			if (find(u) not_eq find(v)) {
				unite(u, v);
				k += edge[i].first;
				cnt++;
			}
		}
		cout << sum - k << '\n';
	}

	return 0;
}