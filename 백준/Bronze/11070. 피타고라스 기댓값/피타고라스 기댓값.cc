#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int test_case = 0; test_case < T; test_case++) {
        int n, m; cin >> n >> m;
        vector<vector<int>> team(n, vector<int>(2));
        for (int game = 0, a, b, p, q; game < m; game++) {
            cin >> a >> b >> p >> q;
            team[a - 1][0] += p; team[a - 1][1] += q;
            team[b - 1][0] += q; team[b - 1][1] += p;
        }

        double largest = 0, smallest = 1e9, Ss, As;

        for (int i = 0; i < n; i++) {
            Ss = team[i][0] * team[i][0];
            As = team[i][1] * team[i][1];
            if (Ss == 0 and As == 0) {
                largest = max(largest, static_cast<double>(0));
                smallest = min(smallest, static_cast<double>(0));
            }
            else {
                double W = Ss / (Ss + As);
                largest = max(largest, W);
                smallest = min(smallest, W);
            }
        }

        cout << static_cast<int>(largest * 1000) << '\n' << static_cast<int>(smallest * 1000) << '\n';
    }



    return 0;
}