#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define INF (static_cast<int>(1e9))
#define endl '\n'

typedef pair<int, int> PAIR;
int main(void) {
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	int J; cin >> J; J--;
	int K; cin >> K;
	map<int, char> house;
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < K; k++) {
			int p; cin >> p;
			house.insert(make_pair(p - 1, 'A' + i));
		}
	}

	vector<vector<PAIR>> graph(N);
	for (int i = 0; i < M; i++) {
		int X, Y, Z; cin >> X >> Y >> Z;
		graph[X - 1].push_back(PAIR(Y - 1, Z));
		graph[Y - 1].push_back(PAIR(X - 1, Z));
	}

	int cnt[2] = { 0, 0 };
	vector<bool> visited(N, false);
	vector<int> cost(N, INF);
	priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
	pq.push(PAIR(0, J));
	cost[J] = 0;

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

	int minimum[2] = { INF, INF };
	for (int i = 0; i < N; i++) {
		if (house[i] == 'A') {
			minimum[0] = min(minimum[0], cost[i]);
		}
		else if (house[i] == 'B') {
			minimum[1] = min(minimum[1], cost[i]);
		}
	}
	
	if (minimum[0] != INF || minimum[1] != INF) {
		cout << (minimum[0] > minimum[1] ? 'B' : 'A') << endl;
		cout << min(minimum[0], minimum[1]) << endl;
	}
	else cout << (-1) << endl;

	return 0;
}