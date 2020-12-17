/**
* Gleb Zavyalov (zavygy@gmail.com)
*/

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

vector<int> Dijkstra(start, edges) {
    vector<int> d(n, INT_MAX), u(n, 0)
    d[start] = 0;
    forn(_, n) {
        int x = -1;
        // O(V^2)
        forn(i, n)
            if (u[i] == 0 && (x == -1 || d[i] < d[x]))
                x = i
        if (x == -1)
            break;
        u[x] = 1;
        // O(E)
        for (Edge e : edges[x])
            d[e.to] = min(d[e.to], d[x] + e.weight);
    }
    return d;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


}

/* stuff you should look for
   * int overflow, array bounds
   * special cases (n=1?), set tle
   * do smth instead of nothing and stay organized
*/