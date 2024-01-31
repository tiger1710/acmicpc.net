#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

int M, N;
vector<vector<int> > map, dp;

int go(const int& r, const int& c) {
    if (r == M - 1 and c == N - 1) {
        return 1;
    }

    if (dp[r][c] not_eq -1) {
        return dp[r][c];
    }

    static const int dr[4] = { -1, 1, 0, 0 };
    static const int dc[4] = { 0, 0, -1, 1 };
    int res = 0;
    REP (i, 0, 4) {
        const int nextR = r + dr[i];
        const int nextC = c + dc[i];
        if (0 <= nextR and nextR < M and 0 <= nextC and nextC < N and
            map[nextR][nextC] < map[r][c]) {
            res += go(nextR, nextC);
        }
    }

    return dp[r][c] = res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> M >> N;
    map.resize(M, vector<int>(N));
    dp.resize(M, vector<int>(N, -1));
    for (vector<int>& r : map) {
        for (int& c : r) {
            cin >> c;
        }
    }
    
    cout << go(0, 0) << endl;


    return 0;
}
