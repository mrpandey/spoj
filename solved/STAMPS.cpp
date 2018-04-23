#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(int a, int b){return a>b;}

int main(){
	cin.tie(NULL);
	int t; cin >> t;
	for(int k=1; k<=t; k++) {
		int x, n; cin >> x >> n;
		int a[n], sum=0;
		for(int i=0; i<n; i++){
			cin >> a[i];
			sum += a[i];
		}
		cout << "Scenario #" << k << ":\n";
		if(sum<x){
			cout << "impossible\n\n";
			continue;
		}
		sort(a, a+n, cmp);
		int i;
		sum = 0;
		for(i=0; i<n; i++){
			sum += a[i];
			if(sum>=x) break;
		}
		cout << i+1 << "\n\n";
	}
	return 0;
}