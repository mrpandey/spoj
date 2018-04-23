#include<iostream>
#include<vector>

using namespace std;

int sieve[1001] = {0};
vector<int> primes;

void build(){
	sieve[0] = sieve[1] = 1;
	for(int i=2; i<1001; i++){
		if(sieve[i]) continue;
		for(int j=2*i; j<1001; j+=i) sieve[j] = 1;
		primes.push_back(i);
	}
}

int gcd(int a, int b){
	if(a<b){
		a = a+b;
		b = a-b;
		a = a-b;
	}
	int r=a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	build();
	int a,b,t; cin >> t;
	while(t--){
		cin >> a >> b;
		a = gcd(a,b);

		int ans=1, ctr;
		for(int i=0; i<primes.size(); i++){
			ctr=1;
			int p = primes[i];
			if(a<p) break;
			while(a%p==0){
				ctr++;
				a /= p;
			}
			ans *= ctr;
		}
		if(a>1) ans *= 2;
		cout << ans << "\n";
	}
	return 0;
}