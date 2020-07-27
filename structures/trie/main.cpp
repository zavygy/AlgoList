/**
* Gleb Zavyalov (zavygy@gmail.com)
*/

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    const int size = 1e5 + 1; // max trie size;
    int mx_cnt = 1; // count of all the Vs in trie
    vector<map<char, int>> trie(size);
    /* 
        What's inside Trie? : )

        trie[v] -- we are int tries node v

        we store map just for saving edges of over trie

        if (trie[current_node][next_char] != 0) we have edge and
        destination of this edge is trie[current_node][next_char]

        if (trie[current_node][next_char] == 0) we dont have an edge and
        we creating new node (mx_cnt++) and creating an edge from current node to mx_cnt
    */
    auto trie_down = [&] (const string &s) {
        int v = 0; // root
        for (char x : s) {
            int &r = trie[v][x];
            if (!r) r = mx_cnt++;
            v = r;
        }
        return v;
    };


}

/* stuff you should look for
   * int overflow, array bounds
   * special cases (n=1?), set tle
   * do smth instead of nothing and stay organized
*/