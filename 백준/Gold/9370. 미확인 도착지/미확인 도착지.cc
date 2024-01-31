#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF (static_cast<int>(1e9))
typedef pair<int, int> p;

vector<int> d(vector<vector<p>>& graph, const int& s) {
	int n = graph.size();
	vector<bool> visited(n, false);
	vector<int> cost(n, INF);
	priority_queue<p> pq;
	pq.push(p(-0, s));
	cost[s] = 0;

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
				pq.push(p(-cost[next], next));
			}
		}
	}

	return cost;
}

int main(void) {
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int n, m, t; cin >> n >> m >> t;
		int s, g, h; cin >> s >> g >> h;
		s--; g--; h--;//start, passed g-h

		vector<vector<p>> graph(n);
		vector<int> target(t);
		for (int i = 0; i < m; i++) {
			int a, b, d; cin >> a >> b >> d;
			graph[a - 1].push_back(p(b - 1, d));
			graph[b - 1].push_back(p(a - 1, d));
		}
		for (auto& t : target) {
			cin >> t; t--;
		}
		sort(target.begin(), target.end());

		vector<int> startcost = d(graph, s);
		int ghstart = startcost[g] > startcost[h] ? g : h;
		vector<int> ghcost = d(graph, ghstart);

		for (int i = 0; i < t; i++) {
			if (startcost[target[i]] - startcost[ghstart] == ghcost[target[i]]) {
				cout << target[i] + 1 << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}