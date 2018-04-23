#include<iostream>

using namespace std;

int main(){
	long long n; cin >> n;
	if(n<=0) cout << "TAK\n";
	else if((n&(n-1))==0){
		cout << "TAK\n";
	}
	else cout << "NIE\n";
	return 0;
}