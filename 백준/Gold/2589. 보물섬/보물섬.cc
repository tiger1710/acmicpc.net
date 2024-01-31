#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> map;
vector<vector<int>> visited;
typedef pair<int, int> pos;
int r, c, tresure;
int dr[4] = { 0,-1,0,1 };
int dc[4] = { -1,0,1,0 };

bool isSafe(int row, int col) {
	if (row < 0 || r <= row || col < 0 || c <= col) return false;
	else return true;
}

void bfs() {
	for (int row = 0; row < r; row++) {
		for (int col = 0; col < c; col++) {
			if (!visited[row][col]) {
				vector<vector<int>> check = visited;
				queue<pos> q;
				q.emplace(row, col); check[q.front().first][q.front().second] = 1;
				while (!q.empty()) {
					pos cur = q.front();
					for (int i = 0; i < 4; i++) {
						pos next = { cur.first + dr[i],cur.second + dc[i] };
						if (isSafe(next.first, next.second) && !check[next.first][next.second]) {
							check[next.first][next.second] = check[cur.first][cur.second] + 1;
							q.push(next);
						}
					}
					q.pop();
				}

				for (int i = 0; i < r; i++) {
					for (int k = 0; k < c; k++) {
						tresure = check[i][k] > tresure ? check[i][k] : tresure;
					}
				}

			}
		}
	}
}

int main(void) {
	cin >> r >> c;
	map.resize(r);
	visited.resize(r);
	for (int i = 0; i < r; i++) {
		map[i].resize(c);
		visited[i].resize(c);
	}
	for (int row = 0; row < r; row++) {
		for (int col = 0; col < c; col++) {
			cin >> map[row][col];
			if (map[row][col] == 'W') visited[row][col] = 1;
		}
		cin.ignore();
	}
	bfs();
	cout << tresure  - 1 << endl;

	return 0;
}