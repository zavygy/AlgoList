/**
* Gleb Zavyalov (zavygy@gmail.com)
*/

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

vector<int> d;
vector<vector<int>> g;

void dfs(int s, int h) {
    d[s] = h;
    for (int x : g[s])
        if (d[x] == -1)
            dfs(x, h + 1);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k; cin >> n >> k;
    d.resize(n, -1); g.resize(n, vector<int>());
    auto log = [](int n) {
        int lg = 0;
        while ((1 << lg) <= n) lg++;
        return lg;
    };

    vector<vector<int>> dp(n, vector<int> (log(n) + 2, 0));
    vector<int> p(n, -1);

    auto preprocess = [&] () {
        forn (i, n) dp[i][0] = p[i];
        forn (j, log(n)) forn (i, n) dp[i][j + 1] = dp[dp[i][j]][j];
    };

    auto lca = [&](int a, int b) {
        if (d[a] < d[b]) swap(a, b);

        for (int i = log(n); i >= 0; i--)
            if (d[dp[a][i]] - d[b] >= 0)
                a = dp[a][i];

        if (a == b) return a;
        for (int i = log(n); i >= 0; i--)
            if (dp[a][i] != dp[b][i])
                a = dp[a][i], b = dp[b][i];

        return p[b];
    };

    forn (i, n - 1) {
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        p[b] = a;
    }

    int root = -1;
    forn (i, n) if (p[i] == -1) root = i;
    dfs(root, 0);
    p[root] = root;
    preprocess();

    forn (i, k) {
        int a, b; cin >> a >> b; a--, b--;
        cout << a + 1 << ' ' << b + 1 << ' ' << d[lca(a, b)] << '\n';
    }
}

/* stuff you should look for
   * int overflow, array bounds
   * special cases (n=1?), set tle
   * do smth instead of nothing and stay organized
*/