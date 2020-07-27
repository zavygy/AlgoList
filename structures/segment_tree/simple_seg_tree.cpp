/**
 * Gleb Zavyalov (zavygy@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

struct SegmentTree {
	int size;
	vector<int64_t> tree;

	SegmentTree(int n) {
		size = 1;
		while (size < n) size *= 2;
		tree.assign(2 * size - 1, 0);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = v;
			return;
		}

		int m = (lx + rx) / 2;
		if (i < m)
			set(i, v, 2 * x + 1, lx, m);
		else
			set(i, v, 2 * x + 2, m, rx);
		
		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}

	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	int64_t sum(int l, int r, int x, int lx, int rx) {
		if (l >= rx || r <= lx) return 0;
		if (lx >= l && rx <= r) return tree[x];
		int m = (lx + rx) / 2;
		int64_t s1 = sum(l, r, 2 * x + 1, lx, m);
		int64_t s2 = sum(l, r, 2 * x + 2, m, rx);
		return s1 + s2;
	}

	int64_t sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
};

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, m; cin >> n >> m;
	SegmentTree st(n);
	forn (i, n) {
		int x; cin >> x;
		st.set(i, x);
	}

	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		if (a % 2) st.set(b, c);
		else cout << st.sum(b, c) << '\n';
	}

	return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/