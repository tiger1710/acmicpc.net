#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

static const int INF = 323456789;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M, X;
    cin >> N >> M >> X;
    vector<vector<int> > road(N, vector<int>(N, INF));
    REP (i, 0, M) {
        int s, e, t; cin >> s >> e >> t;
        road[s - 1][e - 1] = t;
    }
    road[X - 1][X - 1] = 0;

    REP (b, 0, N) {
        REP (i, 0, N) {
            REP (k, 0, N) {
                road[i][k] = min(road[i][k], road[i][b] + road[b][k]);
            }
        }
    }

    int m = -1;
    REP (i, 0, N) {
        m = max(m, road[i][X - 1] + road[X - 1][i]);
    }
    cout << m << endl;

    return 0;
}
