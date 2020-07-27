#include <iostream>
#include <vector>

using namespace std;

string reverse(string s){
	string res = "";
	for(int i = s.size()-1; i >=0; i--){
		res+=s[i];
	}
	return res;
}

struct Hasher {
	int n;
	vector<int> h, deg;
	const int x = 239017, M = 1e9 + 7;

	Hasher (const string &s): n(s.size()), h(n+1, 0), deg(n+1, 1) {
		for(int i = 0; i < n; i++){
			h[i + 1] = ((int64_t)h[i] * x + s[i]) % M;
			deg[i + 1] = ((int64_t)deg[i] * x) % M;
		}
	}

	int getHash (int i, int len) {
		return ((h[i + len] - ((int64_t) h[i] * deg[len])) % M + M) % M;
	};

	int getHashLR (int l, int r) {
		return ((h[r] - ((int64_t) h[l] * deg[r - l])) % M + M) % M;
	};

	int getAllHash() {
		return ((h[0 + n] - ((int64_t) h[0] * deg[n])) % M + M) % M;
	}

};

int main(){

	string s;
	cin >> s;
	Hasher h1(s);
	Hasher h2(reverse(s));


	if (h)

	int l = 0;
	cin >> l;
	int len = 0; 
	cin >> len;
	cout << h1.getHash (l, len) << ' '  << '\n';

	return 0;
}
