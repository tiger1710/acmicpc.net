#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define endl '\n'

typedef pair<int, int> pii;
pii init(const vector<int>& arr, vector<pii>& seg, int index, int from, int to) {
	if (from not_eq to) {
		pii left = init(arr, seg, (index << 1) + 1, from, (from + to) >> 1);
		pii right = init(arr, seg, (index << 1) + 2, ((from + to) >> 1) + 1, to);
		seg[index].first = min(left.first, right.first);
		seg[index].second = max(left.second, right.second);
		return seg[index];
	}
	else {
		seg[index].first = seg[index].second = arr[from];
		return seg[index];
	}
}

pii result(const vector<pii>& seg, int index, int from, int to, const int& start, const int& end) {
	if (to < start or end < from) return pii(1000000001, 0);
	else if (start <= from and to <= end) return seg[index];

	pii left = result(seg, (index << 1) + 1, from, (from + to) >> 1, start, end);
	pii right = result(seg, (index << 1) + 2, ((from + to) >> 1) + 1, to, start, end);
	
	return pii(min(left.first, right.first), max(left.second, right.second));
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, M; cin >> N >> M;

	vector<int> arr(N);
	vector<pii> seg((4 << static_cast<int>(log2(N))) - 1);
	for (int& i : arr) {
		cin >> i;
	}
	init(arr, seg, 0, 0, N - 1);
	
	for (int i = 0, start, end; i < M; i++) {
		cin >> start >> end;
		pii p = result(seg, 0, 0, N - 1, start - 1, end - 1);
		cout << p.first << ' ' << p.second << endl;
	}



	return 0;
}