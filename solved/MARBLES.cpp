#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		if(n==k || n<3 || k==1) {
			cout << 1 << "\n";
			continue;
		}
		unsigned long long ans = 1;
		for(int i=n-k+1; i<n; i++){
			ans = (unsigned long long)(ans * i) / (i-n+k);
		}
		cout << ans << "\n";
	}
}