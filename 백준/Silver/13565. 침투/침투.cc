#include <iostream>
using namespace std;

int M, N;
char percolates[1000][1000];
bool isSafe(int r, int c) {
	if (r < 0 || c < 0 || r >= M || c >= N) return false;
	else return true;
}

void dfs(int r, int c) {
	if (percolates[r][c]) return;
	percolates[r][c] = 1;
	if (r == M - 1) percolates[r][c] = -1;
	if (isSafe(r + 1, c) and not percolates[r + 1][c]) dfs(r + 1, c);
	if (isSafe(r - 1, c) and not percolates[r - 1][c]) dfs(r - 1, c);
	if (isSafe(r, c + 1) and not percolates[r][c + 1]) dfs(r, c + 1);
	if (isSafe(r, c - 1) and not percolates[r][c - 1]) dfs(r, c - 1);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> M >> N; cin.ignore();
	int ch;
	for (int r = 0; r < M; r++) {
		for (int c = 0; c < N; c++) {
			ch = cin.get() - '0';
			percolates[r][c] = ch;
		}
		cin.ignore();
	}

	for (int c = 0; c < N; c++) {
		if (not percolates[0][c]) {
			dfs(0, c);
		}
	}

	for (int c = 0; c < N; c++) {
		if (percolates[M - 1][c] == -1) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
	
	return 0;
}