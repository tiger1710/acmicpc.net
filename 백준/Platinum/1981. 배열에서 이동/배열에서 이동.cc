#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int answer;
int n;
vector<vector<short>> arr;
vector<vector<bool>> visited;

const short dr[4] = { 0,1,0,-1 };
const short dc[4] = { -1,0,1,0 };

short maximum = 0, minimum = 200;

class pos {
public:
	pos(short r, short c) : r(r), c(c) { }
	bool isSafe(void) {
		return !(this->r < 0 || this->c < 0 || this->r >= ::n || this->c >= ::n);
	}
	void visit(void) {
		::visited[this->r][this->c] = true;
	}
	bool visited(void) {
		return ::visited[this->r][this->c];
	}
	short r, c;
};

bool search(pos& p) {
	for (short from = ::minimum; from <= ::maximum - ::answer; from++) {
		short to = from + ::answer;
		if (::arr[0][0] < from || ::arr[0][0] > to) continue;
		for (auto& i : ::visited) {
			i = vector<bool>(::n, false);
		}
		for (size_t i = 0; i < ::n; i++) {
			for (size_t k = 0; k < ::n; k++) {
				if (::arr[i][k] < from || ::arr[i][k] > to) ::visited[i][k] = true;
			}
		}

		queue<pos> q;
		q.push(p);
		p.visit();

		while (!q.empty()) {
			pos cur(q.front());

			if (cur.r == ::n - 1 && cur.c == ::n - 1) return true;

			for (int i = 0; i < 4; i++) {
				pos next(cur.r + ::dr[i], cur.c + ::dc[i]);
				if (next.isSafe() && !next.visited()) {
					q.push(next);
					next.visit();
				}
			}

			q.pop();
		}
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin >> ::n;
	arr.resize(::n);
	visited.resize(::n);
	for (int i = 0; i < ::n; i++) {
		arr[i].resize(::n);
		visited[i].resize(::n);
		for (int k = 0; k < ::n; k++) {
			cin >> arr[i][k];
			maximum = max(maximum, arr[i][k]);
			minimum = min(minimum, arr[i][k]);
		}
	}

	int low = -1, high = ::maximum - ::minimum;
	while (low + 1 < high) {
		::answer = ((low + high) >> 1);

		pos start(0, 0);
		if (search(start)) high = ::answer;
		else low = ::answer;
	}
	cout << high << endl;

	return 0;
}