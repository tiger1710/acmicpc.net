#include <iostream>
#include <queue>

using namespace std;

int bfs(int X) {
	if (X == 1) return 1;
	queue<int> q;
	vector<int> visited;
	visited.resize(X + 1);
	q.push(X);
	visited[X] = 1;
	while (!q.empty()) {
		
		int qSize = q.size();
		
		for (int i = 0; i < qSize; i++) {
			int cur = q.front();
			if (cur == 1) return visited[cur];
			if (!(cur % 3) && !visited[cur / 3]) {
				q.push(cur / 3);
				visited[cur / 3] = visited[cur] + 1;
			}
			if (!(cur % 2) && !visited[cur / 2]) {
				q.push(cur / 2);
				visited[cur / 2] = visited[cur] + 1;
			}
			if ((cur - 1) > 0 && !visited[cur - 1]) {
				q.push(cur - 1);
				visited[cur - 1] = visited[cur] + 1;
			}
			q.pop();
		}
	}
}

int main(void) {
	int X;
	cin >> X;
	cout << bfs(X) - 1 << endl;

	return 0;
}