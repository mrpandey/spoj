#include<iostream>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int a, b; cin >> a >> b;
		if(b==0) {cout << 1 << "\n"; continue;}
		a = a%10;
		if(a<2) {cout << a << "\n"; continue;}

		//ld[i] gives last digit of a^i
		//bool memo[i] gives whether a has i as its
		//last digit
		int ld[10]={0}, memo[10]={0};
		ld[0]=1; ld[1]=a;
		memo[a]=1;
		int d=a, i;
		for(i=2; i<=10; i++){
			d = (d*a)%10;
			if(memo[d]) break;
			ld[i] = d;
			memo[d] = 1;
		}
		ld[0] = ld[--i];
		//now i is the period after which digits repeat
		cout << ld[b%i] << "\n";
	}
	return 0;
}