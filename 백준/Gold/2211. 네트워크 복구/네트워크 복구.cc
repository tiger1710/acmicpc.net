#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF (static_cast<int>(1e9))
#define endl '\n'

typedef pair<int, int> PAIR;
int main(void) {
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	vector<vector<PAIR>> computer(N);
	vector<bool> visited(N);
	vector<int> cost(N, INF);
	priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;

	for (int i = 0; i < M; i++) {
		int A, B, C; cin >> A >> B >> C;
		computer[A - 1].push_back(PAIR(B - 1, C));
		computer[B - 1].push_back(PAIR(A - 1, C));
	}
	
	pq.push(PAIR(0, 0));
	cost[0] = 0;
	
	vector<int> prev(N, -1);
	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second; pq.pop();
		} while (!pq.empty() && visited[cur]);

		if (visited[cur]) break;
		visited[cur] = true;
		
		for (auto& i : computer[cur]) {
			int next = i.first, time = i.second;
			if (cost[next] > cost[cur] + time) {
				cost[next] = cost[cur] + time;
				pq.push(PAIR(cost[next], next));
				prev[next] = cur;
			}
		}
	}
	int cnt = 0;
	for (const int& i : prev) {
		if (i != -1) cnt++;
	}
	cout << cnt << endl;
	for (int i = 0; i < N; i++) {
		if (prev[i] != -1) {
			cout << prev[i] + 1 << ' ' << i + 1 << endl;
		}
	}

	return 0;
}