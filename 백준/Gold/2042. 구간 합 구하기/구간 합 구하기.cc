#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long init(vector<long long>& tree, int node) {
	if (node >= (tree.size() >> 1)) return tree[node];
	return tree[node] = init(tree, (node << 1) + 1) + init(tree, (node << 1) + 2);
}

long long sum(vector<long long>& tree, int node, const int& from, const int& to, int start, int end) {
	if (from > end || to < start) return 0;
	else if (from <= start && end <= to) return tree[node];
	else return sum(tree, (node << 1) + 1, from, to, start, (start + end) >> 1) + sum(tree, (node << 1) + 2, from, to, ((start + end) >> 1) + 1, end);
}

void update(vector<long long>& tree, int b, long long c) {
	long long d = c - tree[b];
	tree[b] = c;
	while (b) {
		b = (b - 1) >> 1;
		tree[b] += d;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	int N, M, K; cin >> N >> M >> K;
	int size = 1;
	while (1 << size++ < N);
	size = (1 << size) - 1;
	vector<long long> tree(size);
	size >>= 1;
	for (int i = 0; i < N; i++) {
		cin >> tree[size + i];
	}

	init(tree, 0);
	for (int i = 0; i < M + K; i++) {
		int a, b; long long c; cin >> a >> b >> c;
		if (a & 1) {
			update(tree, size + b - 1, c);
		}
		else {
			cout << sum(tree, 0, size + b - 1, size + c - 1, size, size << 1) << '\n';
			//8 ~ 11, 7 ~ 14; 
		}
	}

	return 0;
}