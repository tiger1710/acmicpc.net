#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

vector<vector<int> > maze, dp;
int N, M;
int go(const int& r, const int& c) {
    if (r >= N or c >= M) return 0;

    if (dp[r][c] not_eq -1) {
        return dp[r][c];
    }

    if (r < N) {
        dp[r][c] = max(dp[r][c], go(r + 1, c));
    }
    if (c < M) {
        dp[r][c] = max(dp[r][c], go(r, c + 1));
    }
    /*
    if (r < N and c < M) {
        dp[r][c] = max(dp[r][c], go(r + 1, c + 1));
    }
    */
    dp[r][c] += maze[r][c];
    return dp[r][c];
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    maze.resize(N, vector<int>(M));
    dp.resize(N, vector<int>(M, -1));
    for (vector<int>& r : maze) {
        for (int& c : r) {
            cin >> c;
        }
    }

    cout << go(0, 0) << endl;


    return 0;
}
