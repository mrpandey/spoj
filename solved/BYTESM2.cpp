#include<iostream>
using namespace std;

int max(int a, int b){
	return a>b?a:b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int h, w, x, m=0; cin >> h >> w;
		int a[101][102]={{0}};
		for(int i=1; i<=h; i++){
			for(int j=1; j<=w; j++){
				cin >> x;
				x += max( max(a[i-1][j-1], a[i-1][j]), a[i-1][j+1]);
				a[i][j] = x;
				m = max(m, x);
			}
		}
		cout << m << "\n";
	}
	return 0;
}