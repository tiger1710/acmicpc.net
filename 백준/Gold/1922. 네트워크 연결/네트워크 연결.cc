#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> dist;

int find(int node, vector<int>& parent) {
	if (parent[node] not_eq -1) return parent[node] = find(parent[node], parent);
	return node;
}

void unite(int u, int v, vector<int>& parent) {
	parent[find(u, parent)] = find(v, parent);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N; cin >> N;
	int M; cin >> M;
	vector<int> parent(N, -1);
	priority_queue<dist, vector<dist>, greater<dist>> pq;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		pq.push(dist(c, pii(a - 1, b - 1)));
	}

	int sum = 0;
	int cnt = 0;
	while (cnt < N - 1) {
		dist mindist = pq.top(); pq.pop();
		int uparent = find(mindist.second.first, parent);
		int vparent = find(mindist.second.second, parent);
		if (uparent not_eq vparent) {
			unite(mindist.second.first, mindist.second.second, parent);
			sum += mindist.first;
			cnt++;
		}
	}

	cout << sum << '\n';


	return 0;
}
