#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)
using point = pair<int, int>;

static const int INF = 123456789;
int V, E;
vector<vector<point> > graph;
vector<bool> visited;
vector<int> dist, pre;
int F, T;

void input(void) {
    cin >> V >> E;
    graph.resize(V);
    visited.resize(V, false);
    dist.resize(V, INF);
    pre.resize(V, -1);
    REP (i, 0, E) {
        int u, v ,w; cin >> u >> v >> w;
        graph[u - 1].push_back(point(v - 1, w));
    }
    cin >> F >> T;
}

void dijkstra(void) {
    //priority_queue<point, vector<point>, greater<point> > pq;
    priority_queue<point> pq;
    dist[F - 1] = 0;
    pq.push(point(0, F - 1));

    while (not pq.empty()) {
        int cur;
        do {
            cur = pq.top().second;
            pq.pop();
        } while (not pq.empty() and visited[cur]);
        if (visited[cur] || cur == T - 1) {
            break;
        }

        visited[cur] = true;
        for (const point& p : graph[cur]) {
            const int next = p.first, cost = p.second;
            if (dist[cur] + cost < dist[next]) {
                dist[next] = dist[cur] + cost;
                pre[next] = cur;
                pq.push(point(-dist[next], next));
            }
        }
    }
}

void output(void) {
    cout << dist[T - 1] << endl;
    stack<int> s;
    for (int i = T - 1; i not_eq -1; i = pre[i]) {
        s.push(i + 1);
    }
    cout << s.size() << endl;
    while (not s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    input();
    dijkstra();
    output();


    return 0;
}
