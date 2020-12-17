/**
* Gleb Zavyalov (zavygy@gmail.com)
*/

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main(){
   ios_base::sync_with_stdio(0), cin.tie(0);
   int n; cin >> n;
   int b[n][n];
   forn (i, n)
      forn (j, n)
         cin >> b[i][j];

   map<int, vector<int>> m;
   int k; cin >> k;
   forn (i, k) {  
      int a, b; cin >> a >> b;
      m[b - 1].push_back(a - 1);
   }

   int64_t dp[1 << n][n];
   memset(dp, 0, sizeof(dp));

   forn (mask, (1 << n)) {
      forn (i, n) { // текущее состояние
         forn (j, n) { // хотим поставить
            int state = 0;
            for (int x : m[j]) if (!(mask & (1 << x))) state = 1;
            if (state || (mask & (1 << j)) || !(mask & (1 << i))) continue;
            int64_t &r = dp[mask | (1 << j)][j];
            r = max(dp[mask][i] + b[i][j], r);
         }
      }
   }

   int64_t mx = 0;
   forn (i, n) mx = max(mx, dp[(1 << n) - 1][i]);
   cout << mx << '\n';
}
/* stuff you should look for
   * int overflow, array bounds
   * special cases (n=1?), set tle
   * do smth instead of nothing and stay organized
*/