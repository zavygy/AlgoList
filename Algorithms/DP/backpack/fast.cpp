/*
* Tags: 
*/

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back


void solve() {
    int n, m; cin >> n >> m;
    // n предметов , m - вместимость;
    vector<int> ws(n), cs(n);
    forn (i, n) cin >> ws[i];
    forn (i, n) cin >> cs[i];

    int dp[n + 1][m + 1];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    forn (i, n) {
        forn (j, m) {
            if (dp[i][j] == -1) continue;
            if (j + ws[i] > m) continue;
            int &r = dp[i + 1][j + ws[i]];
            r = max(r, dp[i][j] + cs[i]);
            int &e = dp[i + 1][j];
            e = max(e, dp[i][j]);
        }
        forn (i, n + 1) {
        forn (j, m + 1) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
        }
        cout << '\n';

    }

    int mx = 0;
    forn (i, m + 1) mx = max(mx, dp[n][i]);
    cout << mx << '\n';
}



int main(){
   ios_base::sync_with_stdio(0), cin.tie(0);
   int t = 1;
   // cin >> t;
   for (; t; t--) solve();
}

/*
   * int overflow, array bounds
   * special cases (n=1?), set tle
   * do smth instead of nothing and stay organized
*/
