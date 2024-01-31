#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long make(vector<long long>& tree, int index) {
    if (index >= tree.size()) return 0;
    
	long long leftLen = make(tree, (index << 1) + 1);
	long long rightLen = make(tree, (index << 1) + 2);

	long long gap = leftLen - rightLen;

	if (gap < 0) {
		tree[(index << 1) + 1] -= gap;
		return tree[index] + rightLen;
	}
	else if (gap > 0) {
		tree[(index << 1) + 2] += gap;
		return tree[index] + leftLen;
	}
	return tree[index] + leftLen;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie();
    int k; cin >> k;
    vector<long long> tree((2 << k) - 1);
    long long size = tree.size();
    for (long long i = 1; i < size; i++) {
        cin >> tree[i];
    }
    make(tree, 0);
    long long sum = 0;
    for (int i = 1; i < size; i++) {
        sum += tree[i];
    }
    
    cout << sum << '\n';
    return 0;
}