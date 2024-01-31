#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;
typedef pair<int, int> PAIR;
int main(void) {
	ios::sync_with_stdio(false);
	int N, M, X; cin >> N >> M >> X;
	X--;
	vector<vector<PAIR>> graph(N);
	vector<int> student(N, 0);
	for (int i = 0; i < M; i++) {
		int u, v, w; cin >> u >> v >> w;
		graph[u - 1].push_back(PAIR(v - 1, w));
	}

	for (int i = 0; i < N; i++) {
		if (i == X) continue;
		priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
		vector<int> visited(N, false);
		vector<int> cost(N, numeric_limits<int>::max());
		int start = i;
		cost[start] = 0;
		pq.push(PAIR(0, start));

		while (!pq.empty()) {
			int cur;
			do {
				cur = pq.top().second; pq.pop();
			} while (!pq.empty() && visited[cur]);

			if (visited[cur]) break;
			if (cur == X) break;

			visited[cur] = true;
			for (auto& i : graph[cur]) {
				int next = i.first, distance = i.second;
				if (cost[next] > cost[cur] + distance) {
					cost[next] = cost[cur] + distance;
					pq.push(PAIR(cost[next], next));
				}
			}
		}
		student[i] = cost[X];
	}

	priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
	vector<int> visited(N, false);
	vector<int> cost(N, numeric_limits<int>::max());
	pq.push(PAIR(0, X));
	cost[X] = 0;

	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second; pq.pop();
		} while (!pq.empty() && visited[cur]);


		if (visited[cur]) break;
		visited[cur] = true;

		for (auto& i : graph[cur]) {
			int next = i.first, distance = i.second;
			if (cost[next] > cost[cur] + distance) {
				cost[next] = cost[cur] + distance;
				pq.push(PAIR(cost[next], next));
			}
		}
	}

	int maxCost = student[0] + cost[0];
	for (int i = 1; i < N; i++) {
		maxCost = max(maxCost, student[i] + cost[i]);
	}

	cout << maxCost << '\n';

	return 0;
}