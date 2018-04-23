#include<iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	int arr[n+1] = {0};
	arr[1] = 1;
	for(int i=2; i<=n; i++){
		int ctr=0;
		int p=1, q;
		//no. ways we can write i=p*q where p<=q
		while(true){
			q = i/p;
			if(p>q) break;
			if(p*q==i) ctr++;
			p++;
		}
		arr[i] = arr[i-1] + ctr;
	}
	cout << arr[n] << "\n";
	return 0;
}