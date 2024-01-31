#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> arr;
	int carry = 0;
	arr.push_back(k);

	while (true) {
		int mulN = arr[arr.size() - 1] * n + carry;
		carry = mulN / 10;
		if (carry == 0 && mulN == k) {
			if (arr[arr.size() - 1] == 0) {
				cout << '0' << endl;
				return 0;
			}
			else break;
		}
		arr.push_back(mulN % 10);
	}

	do {
		cout << arr[arr.size() - 1];
		arr.pop_back();
	} while (!arr.empty());
	cout << endl;

	return 0;
}