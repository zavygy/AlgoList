#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

const int UNUSED = -1;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);
	vector<vector<int>> mat_g(n, vector<int>(n, -1));
	vector<int> dist(n, UNUSED);

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a); // optional
		mat_g[a][b] = c;
		mat_g[b][a] = c; // optional
	}

	int start_v, end_v; cin >> start_v >> end_v;
    start_v--; end_v--;
	queue<int> q;
	dist[start_v] = 0;
	q.push(start_v);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int destination : g[v]) {
		    int current_dist = dist[v] +  mat_g[v][destination];
			if (dist[destination] == UNUSED) {
				dist[destination] = current_dist;
                q.push(destination);
            } else if (current_dist < dist[destination]) {
			    dist[destination] = min(dist[destination], current_dist);
                q.push(destination);
            }
        }
	}

	cout << dist[end_v] <<  '\n';


	return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/
