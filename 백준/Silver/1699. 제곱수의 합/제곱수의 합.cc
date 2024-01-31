#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

int N;
vector<int> dp;

int go(const int& n) {
    if (n < 2) return n;

    int& res = dp[n];
    if (res not_eq -1) {
        return res;
    }

    res = go(n - 1) + 1;
    for (int i = 1; i * i <= n; i++) {
        res = min(res, go(n - i * i) + 1);
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    dp.resize(N + 1, -1);

    cout << go(N) << endl;



    return 0;
}
