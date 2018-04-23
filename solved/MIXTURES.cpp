#include<iostream>
#include<climits>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin>>n){
		int a[n][n] = {{0}}, v[n][n] = {{0}};
		for(int i=0; i<n; i++) cin >> v[i][i];
		if(n==1) {cout << "0\n"; continue;}
		
		//a[i][j] = min smoke from mixing i,i+1,...,j, where i<j
		//v[i][j] = mixture value after mixing i,i+1,..,j, where i<j

		for(int d=1; d<n; d++){
			for(int i=0; i<n-d; i++){
				int j = i+d, mn = INT_MAX, temp=0;
				for(int k=i; k<j; k++){
					temp = a[i][k] + a[k+1][j] + v[i][k]*v[k+1][j];
					if(temp<mn) mn = temp;
				}
				a[i][j] = mn;
				v[i][j] = (v[i][i] + v[i+1][j])%100;
			}
		}
		
		cout << a[0][n-1] << "\n";
	}
	return 0;
}