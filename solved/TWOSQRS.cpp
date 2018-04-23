#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int c; cin >> c;
	long long num[c] = {0}, max=-1;
	for(int i=0; i<c; i++){
		cin >> num[i];
		if(num[i]>max) max = num[i];
	}

	int ub = sqrt(max);
	//0 means prime; 1 means not
	int sieve[ub+1] = {0};
	sieve[0] = sieve[1] = 1;
	vector<int> prime;
	for(int i=2; i<=ub; i++){
		if(!sieve[i]) {
			prime.push_back(i);
			for(int j=2*i; j<=ub; j+=i) sieve[j]=1;
		}
	}

	for(int i=0; i<c; i++){

		long long n = num[i];
		if(n<3) {cout << "Yes\n"; continue;}
		if(n%4==3) {cout << "No\n"; continue;}
		int rootn = sqrt(n);
		int j=0;
		bool flag = true;

		while(j<prime.size() && prime[j]<=rootn){
			int p = prime[j];
			if(n%p) {j++; continue;}
			int ctr=0;
			while(n%p==0){
				n /= p;
				ctr++;
			}
			if(p%4==3 && ctr%2) {flag=false; break;}
			rootn = sqrt(n);
			j++;
		}
		//if code reaches here and flag==true,
		//then either n is 1 or it is prime
		if(!flag || n%4==3) {cout << "No\n"; continue;}
		cout << "Yes\n";
	}

	return 0;
}