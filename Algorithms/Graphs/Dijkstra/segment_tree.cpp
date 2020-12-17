/**
* Gleb Zavyalov (zavygy@gmail.com)
*/

#include <bits/stdc++.h>

using namespace std;


#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()


struct SegmentTree {

    vector<pair<int, int>> tree;
    int size_init;
    SegmentTree(const vector<int> &v) {
        size_init = v.size();
        int size = v.size() * 4;
        tree.assign(size, 0);
        build(1, 0, size_init, v);
    }

    void build(int vert, int lx, int rx, vector<int> &v) {
        if (rx - lx == 1) { tree[vert] = {v[lx], lx}; return;}

        int m = (lx + rx) / 2;
        build(vert * 2, lx, m, v);
        build(vert * 2 + 1, m, rx, v);
        tree[vert] = min (tree[vert * 2], tree[vert * 2 + 1]);
    }


    void set(int pos, int value) {
        set(pos, value, 1, 0, size_init);
    }

    void set(int pos, int value, int vert, int lx, int rx) {
        if (rx - lx == 1) {
            tree[vert] = {value, pos};
            return;
        }

        int m = (lx + rx) / 2;
        if (pos < m) set(pos, value, 2 * vert, lx, m);
        else set(pos, value, 2 * vert + 1, m, rx);


        tree[vert] = min(tree[2 * vert], tree[2 * vert + 1]);
    }

    pair<int, int> get(int l, int r) {
        return get(l, r, 1, 0, size_init);
    }


    pair<int, int> get(int l, int r, int vert, int lx, int rx) {
        if (r <= lx || l >= rx)
            return {INT_MAX, -1};
        
        if (l <= lx && rx <= r) 
            return tree[vert];
        

        int m = (lx + rx) / 2;
        auto ml = get(l, r, 2 * vert, lx, m);
        auto mr = get(l, r, 2 * vert + 1, m, rx);

        return min (ml, mr);
    }
};


vector<int> DjikstraSegmentTree(int stat, int end) {
    SegmentTree d(n, vector<int> (n, INT_MAX));
    vector<int> u(n, 0), result(n);
    d.set(start, 0);

    forn (tmp, n) {
        auto x = d.get(0, n).second;
        if (x == -1) return;

        int tmp2 = d.get(x, x + 1);

        for (auto e : edges[x]) {
            if (u[e.to]) continue;
            d.set(e.to, min(d.get(e.to, e.to + 1), tmp2 + e.w));    
        }
        d.set(x, INT_MAX);
        result[x] = tmp2;
        u[x] = 1;
    }
    return result;
}




/* stuff you should look for
   * int overflow, array bounds
   * special cases (n=1?), set tle
   * do smth instead of nothing and stay organized
*/