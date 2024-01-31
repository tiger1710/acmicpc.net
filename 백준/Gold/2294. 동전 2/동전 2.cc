#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

const int IMPOSSIBLE = 123456789;
int n, k;
vector<int> coin;
vector<vector<int> > dp;

int go(const int& N, const int& K) {
    if (N == n) {
        if (K == 0) {
            return 0;
        } else {
            return IMPOSSIBLE;
        }
    }
    if (dp[N][K] not_eq -1) {
        return dp[N][K];
    }

    int res = go(N + 1, K);
    if (coin[N] <= K) {
        res = min(res, go(N, K - coin[N]) + 1);
    }
    return dp[N][K] = res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    coin.resize(n);
    dp.resize(n, vector<int>(k + 1, -1));
    for (int& value : coin) {
        cin >> value;
    }

    int ans = go(0, k);
    if (ans not_eq IMPOSSIBLE) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }



    return 0;
}
