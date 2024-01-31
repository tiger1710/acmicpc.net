#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<int> card;
	int cnt = 0;
	for (int i = 0, val; i < n; i++) {
		cin >> val;
		card.push_back(val);
		if (val < 0) cnt++;
	}
	sort(card.begin(), card.end());

	int p23 = max(card[n - 1] * card[n - 2], card[n - 1] * card[n - 2] * card[n - 3]);
	int m2 = max(card[0] * card[1], card[0] * card[1] * card[n - 1]);
	cout << max(p23, m2) << '\n';
	
	return 0;
}