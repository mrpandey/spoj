#include<iostream>
#include<iomanip>
#define PI 3.14159

using namespace std;

int main(){
	int l;
	cout << setprecision(2) << fixed;
	while(cin >> l){
		if(!l) break;
		double ans = (double)(l*l)/(2*PI);
		cout << ans << "\n";
	}
}