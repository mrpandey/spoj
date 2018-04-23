#include<iostream>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(n==-1) break;
		//n is beehive iff there exits positive k s.t.
		//3k^2 - 3k +1 = n
		if((n-1)%3) {cout << "N\n"; continue;}
		int x = (n-1)/3, lo=1, hi=1e5, mid;
		bool res = false;
		while(lo<=hi){
			mid = lo + (hi-lo)/2;
			long long prod = (long long)mid*(mid-1);
			//cout << lo << " " << mid << " " << hi
			//<< " " << prod << "\n";
			if(prod==x){res=true; break;}
			else if(prod<x) lo = mid+1;
			else hi = mid-1;
		}
		if(res) cout << "Y\n";
		else cout << "N\n";
	}
	return 0;
}