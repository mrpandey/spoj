#include<iostream>
#include<stack>
#include<vector>

using namespace std;

//return length of longest path from source s
int dfs(vector<vector<char> > &lab, int c, int r, int s, int &last) {
	stack<int> stk;
	int vis[r*c] = {0}, d[r*c]={0};
	stk.push(s);
	vis[s] = 1;
	int maxd = 0;
	last = s;

	auto visit = [&](int i, int j, int prnt){
		if(lab[i][j]!='.') return;
		int v = i*c + j;
		if(!vis[v]) {
			stk.push(v);
			vis[v] = 1;
			d[v]=d[prnt]+1;
			if(d[v]>maxd) {maxd=d[v]; last=v;}
		}
	};

	while(!stk.empty()){
		int u = stk.top();
		stk.pop();
		int i=u/c, j=u%c;
		if(i-1>=0) visit(i-1, j, u);
		if(j-1>=0) visit(i, j-1, u);
		if(i+1<r) visit(i+1, j, u);
		if(j+1<c) visit(i, j+1, u);
	}

	return maxd;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int c, r; cin >> c >> r;
		vector<vector<char> > lab(r, vector<char>(c));
		int x = -1;
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				cin >> lab[i][j];
				if(x==-1 && lab[i][j]=='.')
					x = i*c+j;
			}
		}
		int u=-1;
		int ans = dfs(lab, c, r, x, u);
		if(ans==0) {cout << "Maximum rope length is 0.\n"; continue;}
		ans = dfs(lab, c, r, u, x);
		cout << "Maximum rope length is " << ans << ".\n";
	}
	return 0;
}