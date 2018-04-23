#include<iostream>
using namespace std;

int min(int a, int b){
	return a<b?a:b;
}

int main(){
	cin.tie(NULL);
	int t; cin >> t;
	while(t--) {
		string a, b;
		cin >> a >> b;

		int n=a.size(), m=b.size();
		if(n==0 || m==0) {
			cout << (n>m?n:m) << "\n";
			continue;
		}

		int ar[n+1][m+1] = {{0}};
		
		for(int i=0; i<n+1; i++){
			for(int j=0; j<m+1; j++){
				if(i==0) ar[i][j] = j;
				else if(j==0) ar[i][j] = i;
				else if(a[i-1]==b[j-1]){
					ar[i][j] = ar[i-1][j-1];
				}
				else {
					ar[i][j] = 1 + min(ar[i-1][j-1], min(ar[i-1][j], ar[i][j-1]));
				}
			}
		}
		cout << ar[n][m] << "\n";
	}
	return 0;
}