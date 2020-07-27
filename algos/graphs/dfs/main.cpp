#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	vector<vector<int>> g;
	vector<int> used;

	function<void(int)> dfs = [&] (int s) {
        if (!used[s]) used[s] = 1;
        for (int x : g[s])
            if (!used[x])
                dfs(x);
    };

	return 0;
}	

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/
