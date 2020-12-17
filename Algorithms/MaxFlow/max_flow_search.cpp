/**
* Gleb Zavyalov (zavygy@gmail.com)
*/

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

struct MaxFlow {
    struct Edge {
        int to, flow, capacity, rev;
    };
    vector<vector<Edge>> g;
    vector<int> u;
    int s, t, cc;
    MaxFlow (int n, int s, int t) : g(n), u(n), s(s), t(t), cc(0) {} 

    void add_edge(int a, int b, int c = 1) {
        g[a].push_back(b, 0, c, g[b].size());
        g[b].push_back(a, 0, 0, g[a].size() - 1);
    }

    bool dfs(int v) {
        if (v == t) return 1;
        u[v] = cc;

        for (auto e : g[v]) {
            if (e.flow < e.capacity && u[e.to] != cc && dfs(e.to)) {
                e.flow++;
                g[e.to][e.rev].f--;
                return 1;
            }
        }
        return 0;
    }


    int get_flow() {
        int ans = 0;
        cc++;
        while (dfs(s))
            ans++, cc++;
        return ans;
    }

};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


}

/* stuff you should look for
   * int overflow, array bounds
   * special cases (n=1?), set tle
   * do smth instead of nothing and stay organized
*/