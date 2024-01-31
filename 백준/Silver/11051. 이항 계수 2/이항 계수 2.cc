#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

vector<vector<int> > dp;

int go(const int& n, const int& k) {
    static const int MOD = 10007;
    if (n == 0) return 1;
    if (k == 0 or k == n) return 1;

    int& res = dp[n][k];
    if (res not_eq -1) {
        return res;
    }

    res = (go(n - 1, k - 1) + go(n - 1, k)) % MOD;

    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, K; cin >> N >> K;
    dp.resize(N + 1, vector<int>(K + 1, -1));
    cout << go(N, K) << endl;

    return 0;
}
