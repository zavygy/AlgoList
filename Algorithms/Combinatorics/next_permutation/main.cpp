#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;


void next_permutation(vector<int> &perm){
	vector<bool> used(perm.size(), false);
	int prev_max = 0;
	for (int i = perm.size() - 1; i >= 0; i--) {
		if (perm[i] > prev_max) {
			prev_max = perm[i];
			used[perm[i]] == true;
		} else {
			for (int j = perm[i] + 1; j < n; j++) {
				if (used[j]) {
					perm[i] = j;
					used[j] = false;
					break;
				}
			int p = 0;
			for (int j = i + 1; j < n; j++) {
				while (!used[p]) {
					p++;
				}
				perm[j] = p;
				p++;
			}
			break;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);



	return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/

