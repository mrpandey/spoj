#include<iostream>

using namespace std;

int main(){
	int g, b;
	while(1){
		cin >> g >> b;
		if(g==-1 && b==-1) break;
		int ans;
		if(g<=b){
			ans = b/(g+1);
			if(ans*(g+1)<b) ans++;
		}
		else {
			ans = g/(b+1);
			if(ans*(b+1)<g) ans++;
		}
		cout << ans << "\n";
	}
}