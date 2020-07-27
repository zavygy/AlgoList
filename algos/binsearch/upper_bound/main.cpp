#include <iostream>
#include <vector>

using namespace std;

int upper_bound(vector<int> &v, int val){
	int l = -1, r = v.size();
	while(r-l > 1){
		int medium = (r+l)/2;
		if(v[medium] > val){
			r = medium;
		}else{
			l = medium;
		}
	}
	return r;
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int &x: v){
		cin >> x;
	}

	int k;
	cin >> k;
	sort(v.begin(), v.end());
	cout << upper_bound(v, k)  << '\n';


	return 0;
}
