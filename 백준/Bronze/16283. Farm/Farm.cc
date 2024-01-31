#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <limits>
using namespace std;
typedef pair<int, int> pii;

int main(void) {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int a, b, n, w; cin >> a >> b >> n >> w;
   int cnt = 0;
   int anss, ansg;
   for (int i = 1; i < n; i++) {
      int sheep = a * i;
      int goat = b * (n - i);
      if (w == (sheep + goat)) {
         cnt++;
         anss = i; ansg = n - i;
      }
   }
   if (cnt == 1) cout << anss << ' ' << ansg << '\n';
   else cout << -1 << '\n';

   return 0;
}