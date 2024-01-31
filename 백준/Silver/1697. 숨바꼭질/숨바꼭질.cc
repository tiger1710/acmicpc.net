#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> visited;
int BIG;
bool isSafe(int pos) {
	if (pos<0 || pos > BIG + 1) return false;
	else return true;
}

int main(void) {
	int N, K;
	cin >> N >> K;
	BIG = K > N ? K : N;
	queue<int> q;
	q.push(N); visited.resize(BIG + 2);
	visited[N] = 1;
	while (!q.empty()) {
		int cur = q.front();
		if (cur == K) break;
		if (isSafe(cur * 2) && !visited[cur * 2] && cur < K) {
			visited[cur * 2] = visited[cur] + 1;
			q.push(cur * 2);
		}
		if (isSafe(cur-1) && !visited[cur - 1]) {
			visited[cur - 1] = visited[cur] + 1;
			q.push(cur - 1);
		}
		if (isSafe(cur + 1) && !visited[cur + 1] && cur < K) {
			visited[cur + 1] = visited[cur] + 1;
			q.push(cur + 1);
		}
		
		q.pop();
	}
	cout << visited[K] - 1 << endl;

	return 0;
}