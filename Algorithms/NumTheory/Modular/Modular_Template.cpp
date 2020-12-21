/*
* Tags: 
*/

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back


const int64_t MOD = 1e9 + 7;

//base ^ p
int64_t bin_pow(int64_t base, int64_t p) {
    if (p == 1)
        return base;
    if (p % 2 == 0) {
        int64_t t = bin_pow(base, p / 2);
        return t * t % MOD;
    } else {
        return bin_pow(base, p - 1) * base % MOD;
    }
}

int64_t inverse_element(int64_t x) {
    return bin_pow(x, MOD - 2);
}

int64_t divide(int64_t a, int64_t b) {
    return a * inverse_element(b) % MOD;
}

int64_t n_fact[int(3e5 + 1)];

int64_t binomialC (int64_t n, int64_t k)
{
    int64_t down = (n_fact[n - k] * n_fact[k]) % MOD;
    return divide(n_fact[n], down);
}

int main() {
    return 0;
}

/*
   * int overflow, array bounds
   * special cases (n=1?), set tle
   * do smth instead of nothing and stay organized
*/
