#include <iostream>
#include <vector>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie();
	int n, m; cin >> n >> m;
	vector<vector<pair<long long, bool>>> pizzabox(n, vector<pair<long long, bool>>(m));
	vector<int> frontmax(m);
	unsigned long long sum = 0;
	for (int i = 0; i < n; i++) {
		int sidemax = 0;
		for (int k = 0; k < m; k++) {
			long long height;
			cin >> height;
			sum += height;
			pizzabox[i][k] = { height, false };
			if (height > pizzabox[i][sidemax].first) sidemax = k;
			if (height > pizzabox[frontmax[k]][k].first) frontmax[k] = i;
		}
		pizzabox[i][sidemax].second = true;
	}
	for (int i = 0; i < m; i++) {
		pizzabox[frontmax[i]][i].second = true;
	}

	unsigned long long sub = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (pizzabox[i][k].second) {
				sub += pizzabox[i][k].first;
			}
		}
	}

	cout << sum - sub << '\n';


	return 0;
}