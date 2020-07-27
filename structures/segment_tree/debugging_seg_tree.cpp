/**
* Gleb Zavyalov (zavygy@gmail.com)
*/

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

struct Tree {
    vector<int> a;
    Tree() : a(2 * N) { }

    void set(int i, int x)  {
        set(i, x, 1, 0, N);
    }
    void set(int i, int x, int v, int vl, int vr)  {
        if (vr - vl == 1) {
            a[v] = x;
            return;
        }
        int vm = (vl + vr) / 2;
        if (i < vm)
            set(i, x, 2 * v, vl, vm);
        else
            set(i, x, 2 * v + 1, vm, vr);
        a[v] = a[2 * v] + a[2 * v + 1];
    }
//--OUTPUT------
    void output()  {
        output(1, 0, N, 0);
    }
    void output(int v, int vl, int vr, int depth)  {
        int vm = (vl + vr) / 2;
        if (vr - vl > 1)
            output(2 * v, vl, vm, depth + 1);
        // printf("%*sa[%d]=%d\n", 2 * depth, "", v, a[v]);
        printf("%*s%d\n", 2 * depth, "", a[v]); //2 * depth количества пробелов перед a[v]
        if (vr - vl > 1)
            output(2 * v + 1, vm, vr, depth + 1);
    }
//-----------

} t;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


}

/* stuff you should look for
   * int overflow, array bounds
   * special cases (n=1?), set tle
   * do smth instead of nothing and stay organized
*/