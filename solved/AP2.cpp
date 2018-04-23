#include<iostream>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		long long a, b, s;
		cin >> a >> b >> s;
		long long n = (2*s)/(a+b);
		long long d = (b-a)/(n-5);
		long long x = a-2*d;
		cout << n << "\n";
		for(int i=0; i<n; i++)
			cout << x+i*d << " ";
		cout << "\n";
	}
}