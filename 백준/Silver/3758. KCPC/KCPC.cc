#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;//score,submit

class Team {
public:
	int submit_time;
	int submits;
	vector<int> problem;
	Team(const int& problems) {
		this->submits = this->submit_time = 0;
		this->problem.resize(problems);
	}
	void submit(const int& problem_num, const int& score, const int& time) {
		this->submit_time = time;
		this->submits++;
		this->problem[problem_num] = max(this->problem[problem_num], score);
	}
	int totalScore(void) {
		int sum = 0;
		for (int& i : this->problem) sum += i;
		return sum;
	}
};


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		int n, k, ID, m; cin >> n >> k >> ID >> m;
		vector<Team> team(n, Team(k));
		for (int log = 0, i, j, s; log < m; log++) {
			cin >> i >> j >> s;
			team[i - 1].submit(j - 1, s, log);
		}

		int winner = ID - 1, ws = team[ID - 1].totalScore();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (i == winner) continue;
			int t = team[i].totalScore();
			if (ws < t) {
				cnt++;
			}
			else if (ws == t) {
				if (team[i].submits < team[winner].submits) {
					cnt++;
				}
				else if (team[i].submits == team[winner].submits) {
					if (team[i].submit_time < team[winner].submit_time) {
						cnt++;
					}
				}
			}
		}

		cout << cnt + 1 << '\n';
	}


	return 0;
}