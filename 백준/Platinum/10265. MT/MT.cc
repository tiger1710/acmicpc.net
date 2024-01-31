#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

//https://github.com/kks227/BOJ/blob/master/10200/10265.cpp
//https://coloredrabbit.tistory.com/45
//https://blog.naver.com/kks227/220802519976

vector<int> participant, groupNum;
vector<bool> visited, finished;
vector<vector<int> > dp;
vector<pair<size_t, size_t> > group;

int n, k, ans;
int gn = 0;

void dfs(const int& curr) { // scc tarjan
    visited[curr] = true;

    const int& next = participant[curr];

    if (not visited[next]) { // not visited
        dfs(next);
    } else if (not finished[next]) {
        size_t cnt = 0;
        int c = curr;
        do {
            cnt++;
            c = participant[c];
            groupNum[c] = gn;
        } while (curr not_eq c);
        group.push_back(make_pair(cnt, 0));
        gn++;
    }
    group[groupNum[next]].second++;
    groupNum[curr] = groupNum[next];
    finished[curr] = true;
}

int knapsack(const int& curr, const int& capacity) {
    if (curr == group.size()) return 0;
    int& result = dp[curr][capacity];
    if (result not_eq -1) return result;

    result = max(result, knapsack(curr + 1, capacity));
    REP (i, group[curr].first, group[curr].second + 1) {
        if (i <= capacity) {
            result = max(result, knapsack(curr + 1, capacity - i) + i);
        } else break;
    }
    return result;
}

void input(void) {
    cin >> n >> k;
    participant.resize(n);
    groupNum.resize(n);
    visited.resize(n, false);
    finished.resize(n, false);
    for (int& i : participant) {
        cin >> i; i--;
    }
}


void calc(void) {
    REP (i, 0, n) {
        if (not visited[i]) {
            dfs(i);
        }
    }
    dp.resize(gn, vector<int>(k + 1, -1));
    ans = knapsack(0, k);
}

void output(void) {
    cout << ans << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    input();
    calc();
    output();

    return 0;
}