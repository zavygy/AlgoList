#include <iostream>
#include <vector>

using namespace std;



int lower_bound(vector<int> &v, int val){
	int l = -1, r = v.size();
	while(r-l > 1){
		int medium = (r+l)/2;
		if(v[medium] < val){
			l = medium;
		}else{
			r = medium;
		}
	}
	return r;
}



int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for(int &x: v)
		cin >> x;

	sort(v.begin(), v.end());
	int k;
	cin >> k;
	cout << lower_bound(v, k)  << '\n';

	return 0;
}