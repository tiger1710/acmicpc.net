#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'
#define INF (static_cast<int>(1e9))
typedef pair<int, int> PAIR;

void erase(vector<vector<PAIR>>& graph, const vector<int>& cost, const int& N, const int& S, const int& D) {
	queue<int> del;
	del.push(D);

	while (!del.empty()) {
		int cur = del.front();

		for (int i = 0; i < N; i++) {
			for (auto it = graph[i].begin(); it != graph[i].end();) {
				if ((*it).first == cur && cost[i] + (*it).second == cost[cur]) {
					del.push(i);
					it = graph[i].erase(it);
				}
				else it++;
			}
		}

		del.pop();
	}
}

vector<int> d(vector<vector<PAIR>>& graph, const int& N, const int& S, const int& D) {
	priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
	vector<bool> visited(N, false);
	vector<int> cost(N, INF);

	pq.push(PAIR(0, S));
	cost[S] = 0;

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

	return cost;
}

int main(void) {
	ios::sync_with_stdio(false);

	while (true) {
		int N, M; cin >> N >> M;
		if (N == 0 && M == 0) break;
		int S, D; cin >> S >> D;
		vector<vector<PAIR>> graph(N);
		for (int i = 0; i < M; i++) {
			int U, V, P; cin >> U >> V >> P;
			graph[U].push_back(PAIR(V, P));
		}//단방향 그래프
		
		erase(graph, d(graph, N, S, D), N, S, D);
		
		int ans = d(graph, N, S, D)[D];
		if (ans != INF) cout << ans << endl;
		else cout << (-1) << endl;
	}

	return 0;
}