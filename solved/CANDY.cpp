#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(true){
		cin >> n;
		if(n==-1) break;
		int a[n], sum=0;
		for(int i=0; i<n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		int avg = sum/n;
		if(avg*n != sum) {cout << "-1\n"; continue;}
		int ans=0;
		for(int i=0; i<n; i++){
			if(a[i]<avg) ans += avg-a[i];
		}
		cout << ans << "\n";
	}
	return 0;
}