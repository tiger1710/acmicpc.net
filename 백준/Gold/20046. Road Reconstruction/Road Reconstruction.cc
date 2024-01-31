#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)
using point = pair<int, int>;
using dPoint = pair<int, point>;

static const point d[4] = { point(-1, 0), point(1, 0), point(0, -1), point(0, 1) };
static const int INF = 123456789;
int m, n;
vector<vector<int> > road;
vector<vector<int> > dist;
vector<vector<bool> > visited;

bool condition(const point& from, const point& to) {
    return
        0 <= to.first and to.first < m and 0 <= to.second and to.second < n and
        road[to.first][to.second] != -1 and
        dist[from.first][from.second] + road[to.first][to.second] < dist[to.first][to.second];
}

void input(void) {
    cin >> m >> n;
    road.resize(m, vector<int>(n));
    dist.resize(m, vector<int>(n, INF));
    visited.resize(m, vector<bool>(n, false));
    for (vector<int>& row : road) {
        for (int& col : row) {
            cin >> col;
        }
    }
}

int dijkstra(const point& p) {
    if (road[p.first][p.second] == -1) return INF;
    dist[p.first][p.second] = road[p.first][p.second];

    priority_queue<dPoint, vector<dPoint>, greater<dPoint> > pq;
    pq.push(dPoint(dist[p.first][p.second], point(0, 0)));

    while (not pq.empty()) {
        point cur;
        do {
            cur = pq.top().second;
            pq.pop();
        } while (not pq.empty() and visited[cur.first][cur.second]);
        if (visited[cur.first][cur.second]) {
            break;
        }

        visited[cur.first][cur.second] = true;
        for (const point& diff : d) {
            const point next = point(cur.first + diff.first, cur.second + diff.second);
            if (condition(cur, next)) {
                dist[next.first][next.second] = dist[cur.first][cur.second] + road[next.first][next.second];
                pq.push(dPoint(dist[next.first][next.second], next));
            }
        }
    }

    /*
    REP (r, 0, m) {
        REP (c, 0, n) {
            cout << dist[r][c] << ' ';
        }
        cout << endl;
    }*/

    return dist[m - 1][n - 1];
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    input();
    int ans = dijkstra(point(0, 0));
    cout << (ans == INF ? -1 : ans) << endl;



    return 0;
}
