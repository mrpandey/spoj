#include<iostream>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(!n) break;

		int a[n+1];
		for(int i=1; i<=n; i++) cin >> a[i];
		bool ambi=true;
		for(int i=1; i<=n; i++){
			if(a[a[i]]!=i) {ambi=false; break;}
		}
		if(ambi) cout << "ambiguous\n";
		else cout << "not ambiguous\n";
	}
	return 0;
}