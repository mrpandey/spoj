#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int x; cin >> x;
		if(x==1) {cout << "TERM 1 IS 1/1\n"; continue;}
		int lo=1, hi=10000, mid, prod;
		while(lo<hi){
			mid = lo + (hi-lo)/2;
			if(mid==lo) break;
			prod = (mid*(mid+1))/2;
			if(x<=prod) hi = mid;
			else lo = mid;
		}
		prod = (lo*(lo+1))/2;
		int k = x - prod - 1, n=lo;
		cout << "TERM " << x << " IS ";
		if(n%2){
			cout << k+1 << "/" << n+1-k << "\n";
		}
		else{
			cout << n+1-k << "/" << k+1 << "\n";
		}
	}
	return 0;
}