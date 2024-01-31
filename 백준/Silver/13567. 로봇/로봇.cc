#include <iostream>
#include <string>
using namespace std;

enum HEAD {
	RIGHT, DOWN, LEFT, UP
};

class Robot {
private:
	int heading = RIGHT;
	pair<int, int> current = { 0, 0 };
public:
	pair<int, int> getPos(void) { return this->current; }
	void MOVE(const int& d) {
		switch (this->heading) {
		case RIGHT:
			this->current.first += d;
			break;
		case DOWN:
			this->current.second -= d;
			break;
		case LEFT:
			this->current.first -= d;
			break;
		case UP:
			this->current.second += d;
			break;
		default:
			break;
		}
	}
	void TRUN(const int& p) {
		if (p) this->heading = (this->heading + 1) % 4;
		else this->heading = ((--this->heading) % 4 + 4) % 4;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	Robot robot;
	int M, n; cin >> M >> n; pair<int, int> pos;
	for (int i = 0; i < n; i++) {
		string s; int k; cin >> s >> k;
		if (s == "MOVE") {
			robot.MOVE(k);
		}
		else {
			robot.TRUN(k);
		}
		pos = robot.getPos();
		if (pos.first < 0 || pos.first > M || pos.second < 0 || pos.second > M) {
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << pos.first << ' ' << pos.second << '\n';

	return 0;
}