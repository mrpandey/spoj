#include<iostream>
#include<vector>
#define vvi vector<vector<int>>
#define P 1000000007
using namespace std;

vvi mat_mult(vvi a, vvi b){
	int p=a.size(), q=b.size(), r=b[0].size();
	vvi prod(p, vector<int>(r));
	for(int i=0; i<p; i++){
		for(int j=0; j<r; j++){
			long long sum = 0;
			for(int k=0; k<q; k++){
				sum += (long long)a[i][k]*b[k][j];
			}
			sum %= P;
			prod[i][j] = sum;
		}
	}
	return prod;
}

vvi mat_exp(vvi a, int p){
	if(p==1) return a;
	vvi res = {{1,0},{0,1}};
	while(p>0){
		if(p%2) res = mat_mult(res, a);
		a = mat_mult(a,a);
		p /= 2;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		n += 1; m += 2;
		//f(m)-f(n) is the ans now
		vvi a = {{0,1},{1,1}};
		vvi fn = mat_mult( {{0,1}}, mat_exp(a, n-1));
		vvi fm = mat_mult(fn, mat_exp(a, m-n));
		int ans = n==1?(P+fm[0][1]-1)%P:(P+fm[0][1]-fn[0][1])%P;
		cout << ans << "\n";
	}
	return 0;
}