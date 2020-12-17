/**
* Gleb Zavyalov (zavygy@gmail.com)
*/

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

vector<int> DijkstraSet(start, edges) {
    vector<int> d(n, INT_MAX);
    set<pair<int,int>> s;
    d[start] = 0;
    forn(i, n)
        s.insert({d[i], i});
    forn(_, n) {
        // O(VlogV)
        int x = s.begin()->second;
        s.erase(s.begin());
        // O(ElogV)
        for (Edge e : edges[x]) {
            int i = e.to, d1 = d[x] + e.weight;
            if (d1 < d[i]) {
                s.erase({d[i], i});
                d[i] = d1;
                s.insert({d[i], i});
            }
        }
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