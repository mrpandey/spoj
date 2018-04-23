#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//sieve[i] = 0 means prime
	int sieve[1001] = {0};
	vector<int> prime;
	sieve[0] = sieve[1] = 1;
	for(int i=2; i<1001; i++){
		if(sieve[i]) continue;
		prime.push_back(i);
		for(int j=2*i; j<1001; j+=i) sieve[j]=1;
	}

	int t; cin >> t;

	while(t--){
		int n; cin >> n;
		if(n==1) {cout << "1\n"; continue;}
		int phi = n;
		for(int i=0; i<prime.size(); i++){
			if(n<prime[i]) break;
			if(n%prime[i]) continue;
			phi /= prime[i];
			phi *= prime[i]-1;
			while(n%prime[i]==0) n /= prime[i];
		}
		if(n>1000) {
			phi /= n;
			phi *= n-1;
		}
		cout << phi << "\n";
	}
	
	return 0;
}