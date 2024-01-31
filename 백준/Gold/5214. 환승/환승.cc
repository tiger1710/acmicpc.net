#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF (static_cast<int>(1e9))
typedef pair<int, int> PAIR;
int main(void) {
	ios::sync_with_stdio(false);
	int N, K, M; cin >> N >> K >> M;

	priority_queue<PAIR> pq;
	vector<vector<int>> graph(N + M);
	vector<bool> visited(N + M, false);
	vector<int> cost(N + M, INF);

	for (int m = 0; m < M; m++) {
		for (int k = 0; k < K; k++) {
			int n; cin >> n; n--;
			graph[n].push_back(N + m);
			graph[N + m].push_back(n);
		}
	}
	
	pq.push(PAIR(-0, 0));
	cost[0] = 0;

	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second; pq.pop();
		} while (pq.empty() && visited[cur]);
		if (visited[cur]) break;
		visited[cur] = true;

		for (auto& next : graph[cur]) {
			int distance = next >= N ? 0 : 1;
			if (cost[next] > cost[cur] + distance) {
				cost[next] = cost[cur] + distance;
				pq.push(PAIR(-cost[next], next));
			}
		}
	}

	if (cost[N - 1] != INF) cout << cost[N - 1] + 1 << endl;
	else cout << -1 << endl;
	return 0;
}