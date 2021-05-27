#define MULT 0
#define DBG 1

#if DBG
    #define _GLIBCXX_DEBUG 1
#endif

#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second

#if DBG
    #define dbg(x) cerr << (#x) << ": " << (x) << '\n'
#else
    #define dbg(x) 0
    #define cerr if(false)cerr
#endif

struct TwoSat {
    int n, col = 1;
    vector<vector<int>> G, Gr;
    vector<int> topological, used, color, ans, order;
    TwoSat(int _) : n(_ * 2), G(n), Gr(n), used(n, 0), color(n), ans(_, -1) {}

    void __add(int a, int b) {
        G[a].pb(b);
        Gr[b].pb(a);
    }

    void add_edge(int u, int a, int v, int b) {
        // (x_u = a) || (x_v = b)
        __add((u << 1) + (a ^ 1), (v << 1) + b);
        __add((v << 1) + (b ^ 1), (u << 1) + a);
    }

    void dfs(int v) {
        used[v] = 1;
        for (int x : G[v])
            if (!used[x])
                dfs(x);
        topological.pb(v);
    }

    void strength(int v) {
        color[v] = col;
        order.pb(v);
        for (int x : Gr[v])
            if (!color[x])
                strength(x);
    }

    int solve() {
        forn (i, n)
            if (!used[i])
                dfs(i);

        reverse(all(topological));
        for (int i : topological)
            if (!color[i])
                strength(i), col++;
        
        for (int i = 0; i < n - 1; i += 2) {
            if (color[i] == color[i + 1]) {
                return 0;
            }
        }

        reverse(all(order));
        for (int x : order)
            if (ans[x / 2] == -1)
                ans[x / 2] = x & 1;
        
        return 1;
    }

    void out() {
       
    }
};

void solve() {
    int n, m; cin >> n >> m;
    TwoSat twoSat(n);
    forn (i, m) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        twoSat.add_edge(a, b, c, d);
    }
    cout << twoSat.solve() << '\n';
    cout << "ans: " << '\n';
    for (int x : twoSat.ans) cout << x << ' ';
    cout << '\n';

}


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   int t = 1;
   if (MULT) cin >> t;
   for (; t; t--) solve();
}

/*
    * int overflow, array bounds
    * special cases (n = 1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/
