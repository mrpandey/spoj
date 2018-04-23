#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	for(int j=1; j<=t; j++){
		int n; cin >> n;
		if(n==0) {
			cout << "Case " << j << ": 0\n";
			continue;
		}
		long long f[n] = {0}, x;
		for(int i=0; i<n; i++){
			cin >> x;
			if(i==0) {f[i]=x; continue;}
			if(i==1) {
				f[i] = x>f[i-1] ? x : f[i];
				continue;
			}
			long long sum = f[i-2] + x;
			f[i] = sum>f[i-1] ? sum : f[i-1];
		}
		cout << "Case " << j << ": " << f[n-1] << "\n";
	}
	return 0;
}