#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF (static_cast<int>(1e9))
#define endl '\n'
typedef pair<int, int> PAIR;
int main(void) {
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;

	priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
	vector<vector<int>> graph(N);
	vector<bool> visited(N);
	vector<int> cost(N, INF);

	for (int i = 0; i < M; i++) {
		int A_i, B_i; cin >> A_i >> B_i;
		graph[A_i - 1].push_back(B_i - 1);
		graph[B_i - 1].push_back(A_i - 1);
	}

	pq.push(PAIR(0, 0));
	cost[0] = 0;

	
	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second; pq.pop();
		} while (!pq.empty() && visited[cur]);

		if (visited[cur]) break;
		visited[cur] = true;

		for (auto& next : graph[cur]) {
			if (cost[next] > cost[cur] + 1) {
				cost[next] = cost[cur] + 1;
				pq.push(PAIR(cost[next], next));
			}
		}
	}
	int where = 0, maximum = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (cost[i] > maximum) {
			where = i;
			maximum = cost[i];
			cnt = 1;
		}
		else if (cost[i] == maximum) cnt++;
	}

	cout << where + 1 << ' ' << cost[where] << ' ' << cnt << endl;

	return 0;
}