/**
* Gleb Zavyalov (zavygy@gmail.com)
*/

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const int MX_SIZE = 1e5;
struct Hasher {
    const int P = 239017;
    string s;
    int n;
    int64_t deg[MX_SIZE], h[MX_SIZE];
    Hasher(string inp) : s(inp), n(inp.size()) {
        forn (i, n) {
            h[i + 1] = h[i] * P + s[i];
            deg[i + 1] = deg[i] * P;
        }
    }

    int64_t get(int l, int r) {
        return h[r + 1] - h[l] * deg[r - l + 1];
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