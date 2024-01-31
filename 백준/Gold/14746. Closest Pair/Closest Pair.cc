#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m;
	int c1, c2; cin >> c1 >> c2;

	vector<int> P(n), Q(m);
	for (int& x : P) cin >> x;
	for (int& x : Q) cin >> x;

    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());

    int pIndex = 0, qIndex = 0, minimum = abs(P[pIndex] - Q[qIndex]), cnt = 0;


    while (pIndex < n and qIndex < m) {
        int gap = abs(P[pIndex] - Q[qIndex]);
        if (gap < minimum) {
            minimum = gap;
            cnt = 1;
        }
        else if (gap == minimum) cnt++;

        if (P[pIndex] < Q[qIndex]) {
            pIndex++;
        }
        else qIndex++;
    }

    cout << abs(c1 - c2) + minimum << ' ' << cnt << '\n';

	return 0;
}