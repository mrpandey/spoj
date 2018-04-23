#include<iostream>
using namespace std;

int min(int a, int b){
	return a<b?a:b;
}

int main(){
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int n = s.size();
		if(n<2) {cout << n << "\n"; continue;}

		int dp[n][n] = {{0}};
		for(int d=1; d<n; d++){
			for(int i=0; i<n-d; i++){
				int j = d+i;
				if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1];
				else dp[i][j] = 1 + min(dp[i][j-1], dp[i+1][j]);
			}
		}
		cout << dp[0][n-1] << "\n";
	}
	return 0;
}