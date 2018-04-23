#include<iostream>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		long long x, sum=0;
		for(int i=0; i<n; i++){
			cin >> x;
			sum += x%n;
		}
		sum %= n;
		if(sum) cout << "NO\n";
		else cout << "YES\n";
	}
}