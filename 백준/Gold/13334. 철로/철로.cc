#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;


bool cmp(const pii& a, const pii& b) {
	return a.second < b.second;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	vector<pii> person;
	for (int i = 0, f, t; i < n; i++) {
		cin >> f >> t;
		if (f > t) {
			swap(f, t);
		}
		person.push_back({ f,t });
	}
	int d; cin >> d;
	sort(person.begin(), person.end(), cmp);

	int ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		pq.push(person[i].first);
		while (not pq.empty() and pq.top() < person[i].second - d) pq.pop();
		ans = ans > pq.size() ? ans : pq.size();
	}

	cout << ans << '\n';


	return 0;
}