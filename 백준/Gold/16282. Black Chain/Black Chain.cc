#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <limits>
using namespace std;
typedef pair<int, int> pii;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	long long n; cin >> n;
	for (long long i = 1; i <= 1e18; i++) {
		long long sum = i + 1;
		long long mult = i + 1;
		for (int k = 0; k < i; k++) {
			mult <<= 1;
			sum = sum + mult;
		}
		sum += i;
		if (n <= sum) {
			cout << i << '\n';
			return 0;
		}
	}

	return 0;
}