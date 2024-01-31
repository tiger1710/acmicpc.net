#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
using namespace std;

constexpr int MOD = 1000000007;

long long init(const vector<long long>& arr, vector<long long>& seg, int index, int from, int to) {
	if (from not_eq to) {
		return seg[index] = ((init(arr, seg, (index << 1) + 1, from, (from + to) >> 1)) * (init(arr, seg, (index << 1) + 2, ((from + to) >> 1) + 1, to))) % MOD;
	}
	else {
		return seg[index] = arr[from];
	}
}

long long update(vector<long long>& seg, int index, int from, int to, const int& pos, const int& d) {
	if (pos < from or to < pos) return seg[index];
	else if (from == to and from == pos) {
		seg[index] = d; return seg[index];
	}
	return seg[index] = (update(seg, (index << 1) + 1, from, (from + to) >> 1, pos, d) * update(seg, (index << 1) + 2, ((from + to) >> 1) + 1, to, pos, d)) % MOD;
}

long long result(vector<long long>& seg, int index, int from, int to, const int& start, const int& end) {
	if ((to < start) or (end < from)) return 1;
	else if ((start <= from) and (to <= end)) return seg[index];
	return (result(seg, (index << 1) + 1, from, (from + to) >> 1, start, end) * result(seg, (index << 1) + 2, ((from + to) >> 1) + 1, to, start, end)) % MOD;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, M, K; cin >> N >> M >> K;

	vector<long long> arr(N);
	vector<long long> seg((4 << static_cast<int>(log2(N))) - 1);

	for (long long& i : arr) {
		cin >> i;
	}
	init(arr, seg, 0, 0, N - 1);

	for (int i = 0; i < M + K; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a & 1) {
			update(seg, 0, 0, N - 1, b - 1, c);
		}
		else {
			cout << result(seg, 0, 0, N - 1, b - 1, c - 1) << endl;
		}
	}


	return 0;
}