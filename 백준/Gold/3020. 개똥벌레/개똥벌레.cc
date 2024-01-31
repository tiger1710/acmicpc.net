#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

vector<int> down, up, totaldown, totalup, total;
int main(void) {
	ios::sync_with_stdio(false);
	int N, H; cin >> N >> H;
	down.resize(H + 1); up.resize(H + 1); totaldown.resize(H + 1); totalup.resize(H + 1); total.resize(H + 1);
	for (int i = 0; i < N / 2; i++) {
		int d, u; cin >> d >> u;
		down[d]++; up[u]++;
	}

	for (int i = 1; i < H; i++) {
		totaldown[H - i] += down[H - i] + totaldown[H - i + 1];
		totalup[i] += up[H - i + 1] + totalup[i - 1];
	}
	totalup[H] = N / 2;

	int minimum = numeric_limits<int>::max(), cnt = 0;
	for (int i = 1; i <= H; i++) {
		total[i] = totaldown[i] + totalup[i];
		if (minimum > total[i]) {
			minimum = total[i];
			cnt = 1;
		}
		else if (minimum == total[i]) cnt++;
	}

	cout << minimum << ' ' << cnt << '\n';

	return 0;
}