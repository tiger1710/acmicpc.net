#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)
using point = pair<int, int>;

static const int INF = 123456789;
int N, E, v1, v2;
vector<vector<point> > graph;
int oneTov1, oneTov2, v1ToN, v2ToN, mid;

void input(void) {
    cin >> N >> E;
    graph.resize(N);
    REP (i, 0, E) {
        int a, b, c; cin >> a >> b >> c;
        graph[a - 1].push_back(point(b - 1, c));
        graph[b - 1].push_back(point(a - 1, c));
    }
    cin >> v1 >> v2;
}

vector<int> dijkstra(const int& from) {
    priority_queue<point> pq;
    vector<bool> visited(N, false);
    vector<int> dist(N, INF);
    dist[from] = 0;
    pq.push(point(0, from));

    while (not pq.empty()) {
        int cur;
        do {
            cur = pq.top().second;
            pq.pop();
        } while (not pq.empty() and visited[cur]);
        if (visited[cur]) {
            break;
        }

        visited[cur] = true;
        for (const point& p : graph[cur]) {
            const int n = p.first, d = p.second;
            if (dist[cur] + d < dist[n]) {
                dist[n] = dist[cur] + d;
                pq.push(point(-dist[n], n));
            }
        }
    }
    return dist;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    input();
    vector<int> v1dist = dijkstra(v1 - 1);
    vector<int> v2dist = dijkstra(v2 - 1);
    oneTov1 = v1dist[0];
    oneTov2 = v2dist[0];
    mid = v1dist[v2 - 1];
    v1ToN = v1dist[N - 1];
    v2ToN = v2dist[N - 1];

    int ans = min(
        oneTov1 + mid + v2ToN,
        oneTov2 + mid + v1ToN
    );
    cout << (ans < INF ? ans : -1) << endl;

    return 0;
}
