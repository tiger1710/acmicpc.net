#include <iostream>
#include <vector>
using namespace std;

vector<unsigned> tile;
int main(void) {
	ios::sync_with_stdio(false);

	unsigned n;
	cin >> n;
	tile.push_back(1);
	tile.push_back(1);
	for (size_t i = 2; i <= n; i++) {
		tile.push_back((tile[i - 2] * 2 + tile[i - 1]) % 10007);
	}
	cout << tile[n] << endl;

	return 0;
}