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

const point diff[4] = { point(-1, 0), point(1, 0), point(0, -1), point(0, 1) };
static const int& INF = 123456789;
int N;
vector<vector<int> > cave, dist;
vector<vector<bool> > visited;

void input(void) {
    cin >> N;
    if (N == 0) return;
    cave = vector<vector<int> >(N, vector<int>(N));
    dist = vector<vector<int> >(N, vector<int>(N, INF));
    visited = vector<vector<bool> >(N, vector<bool>(N, false));
    for (vector<int>& row : cave) {
        for (int& col : row) {
            cin >> col;
        }
    }
}

bool condition(const point& from, const point& to) {
    const int r = to.first, c = to.second;
    return (0 <= r and r < N and 0 <= c and c < N) and
        dist[from.first][from.second] + cave[r][c] < dist[r][c];
}

int dijkstra(void) {
    priority_queue<dPoint> pq;
    dist[0][0] = cave[0][0];
    pq.push(dPoint(dist[0][0], point(0, 0)));

    while (not pq.empty()) {
        point cur;
        do {
            cur = pq.top().second;
            pq.pop();
        } while (not pq.empty() and visited[cur.first][cur.second]);
        if (visited[cur.first][cur.second] or
            (cur.first == N - 1 and cur.second == N - 1)) {
            break;
        }

        visited[cur.first][cur.second] = true;
        for (const point& d : diff) {
            const point next(cur.first + d.first, cur.second + d.second);
            if (condition(cur, next)) {
                dist[next.first][next.second] = dist[cur.first][cur.second] + cave[next.first][next.second];
                pq.push(dPoint(-dist[next.first][next.second], next));
            }
        }
    }

    return dist[N - 1][N - 1];
}

void output(const int& i, const int& ans) {
    cout << "Problem " << i << ": " << ans << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int i = 0;
    while (true) {
        input();
        if (N == 0) break;
        const int ans = dijkstra();
        output(++i, ans);
    }


    return 0;
}
