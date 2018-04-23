#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n, maj=0, ctr=0, x;
		cin >> n >> x;
		maj=x; ctr=1;
		for(int i=1; i<n; i++){
			cin >> x;
			if(x==maj) ctr++;
			else ctr--;
			if(ctr==0) {
				maj = x;
				ctr++;
			}
		}
	}
	return 0;
}