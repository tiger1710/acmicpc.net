#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'
#define r first
#define c second
const char dr[4] = { 0,1,0,-1 };
const char dc[4] = { -1,0,1,0 };

typedef pair<int, int> pos;
typedef pair<int, pos> PAIR;

int main(void) {
	ios::sync_with_stdio(false);

	vector<int> ans;
	
	int N, M; cin >> N >> M; cin.ignore();
	priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
	vector<vector<bool>> visited(M, vector<bool>(N, false));
	vector<vector<int>> graph(M, vector<int>(N));
	vector<vector<int>> cost(M, vector<int>(N, M * N));
	for (auto& row : graph) {
		for (auto& col : row) {
			col = cin.get() - '0';
		}
		cin.ignore();
	}

	pq.push(PAIR(0, pos(0, 0)));
	cost[0][0] = 0;

	while (!pq.empty()) {
		pos cur;
		do {
			cur = pq.top().second; pq.pop();
		} while (!pq.empty() && visited[cur.r][cur.c]);

		if (visited[cur.r][cur.c]) break;
		visited[cur.r][cur.c] = true;

		for (int i = 0; i < 4; i++) {
			pos next(cur.r + dr[i], cur.c + dc[i]);
			if (!(next.r < 0 || next.c < 0 || next.r >= M || next.c >= N)) {
				if (cost[next.r][next.c] > cost[cur.r][cur.c] + graph[next.r][next.c]) {
					cost[next.r][next.c] = cost[cur.r][cur.c] + graph[next.r][next.c];
					pq.push(PAIR(cost[next.r][next.c], next));
				}
			}
		}
	}
	cout << cost[M - 1][N - 1] << endl;

	return 0;
}