#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	while(true){
		cin >> a >> b >> c;
		if(!a && !b && !c) break;
		if(c-b==b-a) {
			cout << "AP " << (c+b-a) << "\n";
		}
		else {
			cout << "GP " << (c*b)/a << "\n";
		}
	}
	return 0;
}