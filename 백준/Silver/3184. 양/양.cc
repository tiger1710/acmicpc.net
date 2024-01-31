#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> map;
vector<vector<bool>> visited;
int R, C;

class Pos {
public:
	Pos(int r, int c) : r(r), c(c) {}
	int r, c;
};

const char dr[4] = { 0, -1, 0, 1 };
const char dc[4] = { -1, 0, 1, 0 };

bool isSafe(Pos& p) {
	if (p.r < 0 || p.r >= R || p.c < 0 || p.c >= C) return false;
	else return true;
}

void morning(void) {
	queue<Pos> q;
	unsigned remainWolf = 0, remainSheep = 0;
	for (int row = 0; row < R; row++) {
		for (int col = 0; col < C; col++) {
			if (!visited[row][col] && map[row][col] != '#') {
				unsigned wolf = 0, sheep = 0;

				q.push(Pos(row,col));
				visited[row][col] = true;
				
				while (!q.empty()) {
					Pos cur = q.front();
					
					if (map[cur.r][cur.c] == 'o') sheep++;
					else if (map[cur.r][cur.c] == 'v') wolf++;

					for (int i = 0; i < 4; i++) {
						Pos next(cur.r + dr[i], cur.c + dc[i]);
						if (isSafe(next) && !visited[next.r][next.c] && map[next.r][next.c] != '#') {
							q.push(next);
							visited[next.r][next.c] = true;
						}
					}

					q.pop();
				}

				if (wolf < sheep) {
					remainSheep += sheep;
				}
				else {
					remainWolf += wolf;
				}
			}
		}
	}

	cout << remainSheep << ' ' << remainWolf << endl;
}

int main(void) {
	cin >> R >> C;
	map.resize(R);
	visited.resize(R);
	for (int row = 0; row < R; row++) {
		visited[row].resize(C);
		for (int col = 0; col < C; col++) {
			char ch;
			cin >> ch;
			map[row].push_back(ch);
		}
		cin.ignore();
	}
	morning();



	return 0;
}