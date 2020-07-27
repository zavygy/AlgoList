#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()


struct Fenwick {
	int n;
	vector<int> f;

	Fenwick(int n) : n(n), f(n) { }

	void clear() {
		fill(all(f), 0);
	}
	int get(int r) { // O(logn)
		int sum = 0;
		for (; r >= 0; r &= r + 1, r--)
			sum += f[r];
		return sum;
	}	
	void add(int i, int x) { // O(logn)
		for (; i < n; i |= i + 1)
			f[i] += x;
	}	
	int get(int l, int r) {
		return get(r) - get(l-1);
	}
};


int main(){
	int n, q; cin >> n >> q;
	vector<int> v(n, 0);
	while (q--) {
		
	}


	return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/