#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int inf = 1e9;


struct edge{
	int s, f, len;
};

int n, m, start, dest; 
vector<edge> edges;
vector<int> path;
vector<int> dist(n, inf);

void ford_bellman() {
	dist[start] = 0;
	for (int run = 1; run;) {
        run = 0;
		for (int j = 0; j < m; j++) {
			if (dist[edges[j].s] < inf) {
				if (dist[edges[j].f] > dist[edges[j].s] + edges[j].len) {
					dist[edges[j].f] = dist[edges[j].s] + edges[j].len;
					path[edges[j].f] = edges[j].s;
                    run = 1;
				}
			}
		}
	}
}

void recover() { // востановлеие
	if (dist[dest] == inf) {
		// очевидно что
	} else {
		for (int current_v = dest; current_v != -1; current_v = path[current_v]) {
			path.push_back(current_v); // путь в обратном порядке!!!!
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> start >> dest;

	return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/
