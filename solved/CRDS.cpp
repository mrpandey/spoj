#include<iostream>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		long long n; cin >> n;
		long long ans = n*(n+1);
		ans += (n*(n-1))/2;
		ans %= 1000007;
		cout << ans << "\n";
	}
}