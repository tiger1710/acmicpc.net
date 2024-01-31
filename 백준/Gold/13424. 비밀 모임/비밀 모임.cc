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
	int T; cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		int N, M; cin >> N >> M;

		vector<vector<PAIR>> graph(N);

		for (int i = 0; i < M; i++) {
			int a, b, c; cin >> a >> b >> c;
			graph[a - 1].push_back(PAIR(b - 1, c));
			graph[b - 1].push_back(PAIR(a - 1, c));
		}

		int K; cin >> K;
		vector<int> start(K);
		for (int& i : start) {
			cin >> i; i--;
		}

		vector<vector<int>> minimum;
		for (int i = 0; i < K; i++) {
			priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
			vector<bool> visited(N, false);
			vector<int> cost(N, INF);
			pq.push(PAIR(0, start[i]));
			cost[start[i]] = 0;

			while (!pq.empty()) {
				int cur;
				do {
					cur = pq.top().second; pq.pop();
				} while (!pq.empty() && visited[cur]);

				if (visited[cur]) break;
				visited[cur] = true;

				for (auto& n : graph[cur]) {
					int next = n.first, distance = n.second;
					if (cost[next] > cost[cur] + distance) {
						cost[next] = cost[cur] + distance;
						pq.push(PAIR(cost[next], next));
					}
				}
			}

			minimum.push_back(cost);
		}

		int minRoom = INF, room;
		for (int c = 0; c < N; c++) {
			int temp = 0;
			for (int r = 0; r < K; r++) {
				temp += minimum[r][c];
			}
			if (minRoom > temp) {
				minRoom = temp;
				room = c;
			}
		}

		cout << room + 1 << endl;
	}



	return 0;
}