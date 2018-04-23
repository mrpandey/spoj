#include<iostream>

using namespace std;

int main(){
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int z, n, k;
		cin >> z >> n >> k;
		//a=no. of blocks of continuous 1's
		//soln is given by summation of
		//C(n-k-a+1, a) * C(k+a-1, a-1)
		//where a ranges from 1 to gint((n-k+1)/2)
		//x and y are terms of the sequences of
		//the two C() functions
		//below are x and y for a=1
		long long x=n-k, y=1, p=n-k+1, sum=0;
		sum += x*y;
		//p is defined for simplification of expressions
		for(int a=2; a<=p/2; a++){
			x = (x*(p-2*a+1)*(p-2*a+2))/(a*(p-a+1));
			y = (y*(k+a-1))/(a-1);
			sum += x*y;
		}
		cout << z << " " << sum << "\n";
	}
}