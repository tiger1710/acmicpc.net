#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF (static_cast<int>(1e9))
#define endl '\n'

typedef pair<int, int> PAIR;
int main(void) {
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int i = 0; i < T; i++) {

		int n, d, c; cin >> n >> d >> c; c--;
		vector<vector<PAIR>> computer(n);
		vector<bool> visited(n, false);
		vector<int> cost(n, INF);
		priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
		for (int k = 0; k < d; k++) {
			int a, b, s; cin >> a >> b >> s;
			computer[b - 1].push_back(PAIR(a - 1, s));
		}

		int cnt = 0, sec = 0;
		pq.push(PAIR(0, c));
		cost[c] = 0;

		while (!pq.empty()) {
			int cur;
			do {
				cur = pq.top().second; pq.pop();
			} while (!pq.empty() && visited[cur]);

			if (visited[cur]) break;
			cnt++; sec = max(sec, cost[cur]);
			visited[cur] = true;

			for (auto& com : computer[cur]) {
				int next = com.first, time = com.second;
				if (cost[next] > cost[cur] + time) {
					cost[next] = cost[cur] + time;
					pq.push(PAIR(cost[next], next));
				}
			}
		}

		cout << cnt << ' ' << sec << endl;
	}


	return 0;
}