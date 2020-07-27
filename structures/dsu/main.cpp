#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector<int> dsu, rang;


/*
void add_set(int x) {
	dsu[x] = x;
	//rang[x] = 1;
}
*/

void union_set(int x, int y) {
	//int a = get_set(x);
	//int b = get_set(y);
	dsu[get_set(x)] = get_set(y);
	/*
	if (rang[a] > rang[b]) {
		swap(a, b);
	}

	dsu[a] = b;

	if (a == b) {
		rang[a]++;
	}

	rang[a] += rang[b];
	*/


}

int get_set(int x) {
	return x == dsu[x] ? x : dsu[x] = get_set(dsu[x]);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	dsu.resize(n);
	iota(dsu.begin(), dsu.end(), 0);
	rang.assign(n, 1);

	return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/

