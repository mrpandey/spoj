#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	while(cin >> m && cin >> n){
		if(m==0 && n==0) break;
		int c[n+1]={0}, v[n+1]={0};
		for(int i=1; i<=n; i++) cin >> c[i] >> v[i];
		//f[i][j] considers 1-till-ith item when total cost<=j
		//f[][][0] stores total val; f[][][1] stores corresponding cost
		int f[n+1][m+1][2] = {{{0}}};
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(c[i]>j) {
					f[i][j][0] = f[i-1][j][0];
					f[i][j][1] = f[i-1][j][1];
				}
				else {
					int sum = f[i-1][j-c[i]][0] + v[i];
					int costSum = f[i-1][j-c[i]][1] + c[i];
					if(f[i-1][j][0]==sum){
						if(f[i-1][j][1]<=costSum){
							f[i][j][0] = f[i-1][j][0];
							f[i][j][1] = f[i-1][j][1];
						}
						else {
							f[i][j][0] = sum;
							f[i][j][1] = costSum;
						}
					}
					else if(f[i-1][j][0] > sum){
						f[i][j][0] = f[i-1][j][0];
						f[i][j][1] = f[i-1][j][1];
					}
					else {
						f[i][j][0] = sum;
						f[i][j][1] = costSum;
					}
				}
			}
		}
		cout << f[n][m][1] << " " << f[n][m][0] << "\n";
	}
	return 0;
}