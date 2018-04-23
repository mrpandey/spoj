#include<iostream>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int g, m;
		cin >> g >> m;
		int mxg=0, mxm=0, x;
		for(int i=0; i<g; i++){
			cin >> x;
			mxg = max(x, mxg);
		}
		for(int i=0; i<m; i++){
			cin >> x;
			mxm = max(x, mxm);
		}
		if(mxm<=mxg) cout << "Godzilla\n";
		else cout << "MechaGodzilla\n";
	}
	return 0;
}