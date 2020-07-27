#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

const int inf = 1e9 + 7;

const int k = 316;

struct block {
	vector<int> a;
	vector<int64_t> p;
	void init() {
		p.resize(100001, 0);
	}

	void add(int x) { p[x]++; }
	void build() {
		for (int i = 1; i <= 100000; i++) {
			p[i] += p[i - 1];
		}
	}
	int get(int l, int r) {return p[r] - p[l - 1];}
};

int main(){
	int n; cin >> n;
	int q; cin >> q;
	vector<int> v(n);
	vector<block> b(n / k + 1);

	forn (i, n) {
		int x; cin >> x;
		if (!(i % k))
			b[i / k].init();
		v[i] = x;
		b[i / k].add(x);

		if (i % k == k - 1)
			b[i / k].build();
	}

	auto get  = [&] (int l, int r, int K, int L) {
		int64_t cnt = 0;

		int c_l = l / k, c_r = r / k;

		if (c_l == c_r) {
			for (int i = l; i <= r; i++)
				if (v[i] >= K && v[i] <= L)
					cnt++;
			
		} else {
			for (int i = l, end = (c_l + 1) * k - 1; i <= end; ++i)
				if (v[i] >= K && v[i] <= L)
					cnt++;
			
			for (int i = c_l + 1; i <= c_r - 1; ++i) {
				cnt += b[i].get(K, L);
			}
			for (int i = c_r * k; i <= r; ++i)
				if (v[i] >= K && v[i] <= L)
					cnt++;
			
		}

		return cnt;
	};


	
	while (q--) {
		int l, r, K , L; cin >> l >> r >> K >> L;
		l--, r--;
		auto x = get(l, r, K, L);
		cout << x <<  '\n';
	}

	return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/