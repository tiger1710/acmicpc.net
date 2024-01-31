#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'


bool bfs(const vector<vector<int>>& graph) {
	int V = graph.size();
	vector<char> color(V, 0);
	for (int i = 0; i < V; i++) {
		if (!color[i]) {
			queue<int> q;
			q.push(i);
			color[i] = 'R';
			bool c = false;
			while (!q.empty()) {
				int qSize = q.size();
				for (int s = 0; s < qSize; s++) {
					int cur = q.front(); q.pop();
					for (auto& next : graph[cur]) {
						if (!color[next]) {
							q.push(next);
							color[next] = (c ? 'R' : 'B');
						}
						else if (color[cur] == color[next]) return false;
					}
				}
				c = !c;
			}
		}
	}

	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	int K; cin >> K;
	for (int i = 0; i < K; i++) {
		int V, E; cin >> V >> E;
		vector<vector<int>> graph(V);
		for (int e = 0; e < E; e++) {
			int u, v; cin >> u >> v;
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}
	
		cout << (bfs(graph) ? "YES" : "NO") << endl;
	}

	return 0;
}