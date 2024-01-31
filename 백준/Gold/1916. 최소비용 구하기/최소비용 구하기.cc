#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	
	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n);
	vector<int> weight(n, numeric_limits<int>::max());
	vector<bool> visited(n);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		graph[u - 1].push_back(pair<int, int>(v - 1, w));
	}

	int from, to; cin >> from >> to;
	from--; to--;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(pair<int, int>(0, from));
	weight[from] = 0;

	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[cur]);

		if (visited[cur]) break;
		visited[cur] = true;

		for (auto& i : graph[cur]) {
			int next = i.first, distance = i.second;
			if (weight[next] > weight[cur] + distance) {
				weight[next] = weight[cur] + distance;
				pq.push(pair<int, int>(weight[next], next));
			}
		}
	}

	cout << weight[to] << '\n';


	return 0;
}