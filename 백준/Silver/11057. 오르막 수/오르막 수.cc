#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

const int MOD = 10007;
int N;
vector<vector<int> > dp;
int go(const int& n, const int& i) {
    if (n == N) return 1;

    if (dp[n][i] not_eq -1) {
        return dp[n][i];
    }

    int res = 0;
    REP (k, i, 10) {
        res += go(n + 1, k) % MOD;
    }

    return dp[n][i] = res % MOD;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    dp.resize(N, vector<int>(10, -1));
    N--;

    int ans = 0;
    REP (i, 0, 10) {
        ans += go(0, i) % MOD;
    }
    cout << ans % MOD << endl;


    return 0;
}
