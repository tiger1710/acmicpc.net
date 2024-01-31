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
int V, E, K;
vector<vector<point> > graph;
vector<bool> visited;
vector<int> dist;

void input(void) {
    cin >> V >> E >> K;
    graph.resize(V);
    visited.resize(V, false);
    dist.resize(V, INF);
    REP (i, 0, E) {
        int u, v ,w; cin >> u >> v >> w;
        graph[u - 1].push_back(point(v - 1, w));
    }
}

void dijkstra(void) {
    //priority_queue<point, vector<point>, greater<point> > pq;
    priority_queue<point> pq;
    dist[K - 1] = 0;
    pq.push(point(0, K - 1));

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
            const int next = p.first, cost = p.second;
            if (dist[cur] + cost < dist[next]) {
                dist[next] = dist[cur] + cost;
                pq.push(point(-dist[next], next));
            }
        }
    }
}

void output(void) {
    for (const int& d : dist) {
        if (d not_eq INF) {
            cout << d << endl;
            continue;
        }
        cout << "INF" << endl;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    input();
    dijkstra();
    output();


    return 0;
}
