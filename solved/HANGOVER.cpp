#include<iostream>

using namespace std;

int main(){
	float v;
	while(cin >> v){
		if(v==0.00) break;
		int n = 1;
		float sum = 0.0;
		while(v>sum) {
			++n;
			sum += (float)1/n;
		}
		cout << n-1 << " card(s)\n";
	}
	return 0;
}