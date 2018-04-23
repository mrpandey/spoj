#include<iostream>

using namespace std;

int main(){
	int n; cin >> n;
	int x = n%10;
	if(x==0){
		cout << "2\n";
	}
	else {
		cout << "1\n" << x << "\n";
	}
}