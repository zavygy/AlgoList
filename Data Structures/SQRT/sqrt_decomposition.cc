#define MULT 1
#define DBG 0

#if DBG
    #define _GLIBCXX_DEBUG 1
#endif

#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second

#if DBG
    #define dbg(x) cerr << (#x) << ": " << (x) << '\n'
#else
    #define dbg(x) 0
    #define cerr if(false)cerr
#endif

struct Block {
    int bsize;
    vector<int> v;
    int sum = 0;

};

struct Sqrt {


    int n;
    vector<int> v;
    int block_size;
    vector<>
    Sqrt(int n) : n(n), t(n) {
        block_size = sqrt(n);
    }
};


void solve() {
    int n; cin >> n;
    vector<int> v(n);
    forn (i, n) cin >> v[i];
    
    
}


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   int t = 1;
   if (MULT) cin >> t;
   for (; t; t--) solve();
}

/*
    * int overflow, array bounds
    * special cases (n = 1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/