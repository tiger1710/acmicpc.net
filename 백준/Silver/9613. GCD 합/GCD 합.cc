#include <iostream>
#include <vector>
using namespace std;

long long gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		vector<long long> arr(n);
		for (auto& i : arr) {
			cin >> i;
		}

		long long sum = 0;
		for (int i = 0; i < n; i++) {
			for (int k = i + 1; k < n; k++) {
				sum += gcd(arr[i], arr[k]);
			}
		}
		cout << sum << '\n';
	}

	return 0;
}