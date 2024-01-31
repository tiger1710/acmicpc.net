#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define l(index) ((index << 1) + 1)
#define r(index) ((index << 1) + 2)
#define half(from, to) ((from + to) >> 1)

int init(vector<int>& arr, vector<int>& tree, int node, int from, int to) {
	if (from not_eq to) {
		return tree[node] = init(arr, tree, l(node), from, half(from, to)) + init(arr, tree, r(node), half(from, to) + 1, to);
	}
	else return tree[node] = arr[from];
}

void update(vector<int>& tree, int node, const int& index, int from, int to, const int& d) {
	if (index < from or index > to) return;
	tree[node] += d;
	if (from not_eq to) {
		update(tree, l(node), index, from, half(from, to), d);
		update(tree, r(node), index, half(from, to) + 1, to, d);
	}
}

int sum(vector<int>& tree, int node, int from, int to, const int& start, const int& end) {
	if (to < start or end < from) return 0;
	else if (start <= from and to <= end) return tree[node];
	else {
		return sum(tree, l(node), from, half(from, to), start, end) + 
			sum(tree, r(node), half(from, to) + 1, to, start, end);
	}
}


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int t; cin >> t;
	for (int test = 0; test < t; test++) {
		int n, m; cin >> n >> m;
		int h = log2(n + m) + 1;
		vector<int> arr(n + m);
		vector<int> tree((2 << h) - 1);

		for (int i = 0; i < n; i++) {
			arr[i] = 1;
		}
		init(arr, tree, 0, 0, n + m - 1);

		int NEW = n;
		vector<int> index;
		for (int i = 0; i < n; i++) index.push_back(n - i - 1);
		for (int i = 0, pos; i < m; i++, NEW++) {
			cin >> pos; pos--;

			cout << sum(tree, 0, 0, n + m - 1, index[pos] + 1, n + m - 1) << ' ';
			update(tree, 0, index[pos], 0, n + m - 1, -1);
			index[pos] = NEW;
			update(tree, 0, index[pos], 0, n + m - 1, 1);
		}
		cout << '\n';

	}

	return 0;
}