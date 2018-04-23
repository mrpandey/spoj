#include<iostream>
using namespace std;

int main(){
	int n, sum, ctr=0; cin >> n;
	int vis[1000] = {0};
	while(true){
		sum=0;
		int r=0;
		while(n>0){
			r = n%10;
			sum += r*r;
			n /= 10;
		}
		ctr++;
		if(sum==1) {cout << ctr; break;}
		if(vis[sum]) {cout << "-1"; break;}
		vis[sum]=1;
		n = sum;
	}
	return 0;
}