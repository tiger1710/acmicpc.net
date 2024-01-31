#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

class Way {
public:
	Way(const int& dist, const int& from, const int& to) : dist(dist), from(from), to(to) { }
	int dist, from, to;
};
bool operator <(const Way& a, const Way& b) {
	return a.dist > b.dist;
}
int find(vector<int>& parent, int planet) {
	if (parent[planet] not_eq -1) return parent[planet] = find(parent, parent[planet]);
	else return planet;
}
void unite(vector<int>& parent, int x, int y) {
	x = find(parent, x);
	y = find(parent, y);
	parent[x] = y;
}

typedef pair<int, int> pii;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N; cin >> N;
	vector<pii> x, y, z;
	for (int i = 0; i < N; i++) {
		int xi, yi, zi; cin >> xi >> yi >> zi;
		x.push_back(pii(xi, i));
		y.push_back(pii(yi, i));
		z.push_back(pii(zi, i));
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());
	priority_queue<Way,vector<Way>,less<Way>> pq;
	vector<int> parent(N, -1);
	for (int i = 0; i < N - 1; i++) {
		pq.push(Way(abs(x[i].first - x[i + 1].first), x[i].second, x[i + 1].second));
		pq.push(Way(abs(y[i].first - y[i + 1].first), y[i].second, y[i + 1].second));
		pq.push(Way(abs(z[i].first - z[i + 1].first), z[i].second, z[i + 1].second));
	}

	int cnt = 0;
	int ans = 0;
	while (cnt < N - 1) {
		int from = pq.top().from, to = pq.top().to;
		if (find(parent, from) not_eq find(parent, to)) {
			unite(parent, from, to);
			ans += pq.top().dist;
			cnt++;
		}
		pq.pop();
	}
	cout << ans << endl;
		


	return 0;
}