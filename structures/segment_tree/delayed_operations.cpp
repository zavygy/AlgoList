/**
* Gleb Zavyalov (zavygy@gmail.com)
*/

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

struct SegmentTree {
    // Дерево отрезков на get() -> максимум, set() {[l, r] = x}
    int size;
    vector<int> tree;

    SegmentTree (int n) : size(n), tree(n * 4, INT_MIN) {};

    void set(int l, int r, int x) {
        set(l, r, x, 1, 0, size);
    };

    void set(int l, int r, int x, int v, int lx, int rx) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            tree[v] = x;
            return;
        }

        if (tree[v] != INT_MIN) {
            tree[v * 2] = tree[v * 2 + 1] = tree[v];
            tree[v] = INT_MIN;
        }

        int m = (rx + lx) / 2;
        set(l, r, x, v * 2, lx, m);
        set(l, r, x, v * 2 + 1, m, rx);
    };

    int get(int l, int r) {
        return get(l, r, 1, 0, size);
    }

    int get(int l, int r, int v, int lx, int rx) {
        if (lx >= r || rx <= l) return INT_MIN;
        if (l <= lx && rx <= r) return tree[v];
        if (tree[v] != INT_MIN) return tree[v];

        int m = (rx + lx) / 2;
        int vl = get(l, r, v * 2, lx, m);
        int vr = get(l, r, v * 2 + 1, m, rx);
        return max(vl, vr);
    }
};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    SegmentTree t(10);
    forn (i, 10)
        t.set(i, i + 1, 0);

    int m; cin >> m; 
    while (m--) {
        int x; cin >> x;
        if (x) {
            int l, r, val; cin >> l >> r >> val;
            t.set(l, r, val);
        } else {
            int l, r; cin >> l >> r;
            cout << t.get(l, r) << '\n';
        }
    }

}

/* stuff you should look for
   * int overflow, array bounds
   * special cases (n=1?), set tle
   * do smth instead of nothing and stay organized
*/