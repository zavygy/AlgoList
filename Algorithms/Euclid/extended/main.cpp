#include <iostream>

using namespace std;

typedef long long int ll;

ll extended_gcd(ll a, ll b, ll &x, ll &y){
	if(b == 0){
		x = 1, y = 0;
		return a;
	}

	ll k = a/b;
	ll x1, y1;

	ll g = extended_gcd(b, a%b, x1, y1);
	// x1*b + y1*(a%b) = g
	// x1*b + y1*(a-b*k) = g
	// a*y1 + b*(x1-y1*k) = g
	x = y1;
	y = x1 - y1*k;
	return g;
}


int main(){
	ll a, b, c, x, y;
	cin >> a >> b >> c;

	ll g = extended_gcd(a, b, x, y);

	if(c%g != 0){
		cout << -1 << '\n';
	}else{
		cout << -x*c/g << ' ' << -y*c/g << '\n';
	}

	return 0;
}
