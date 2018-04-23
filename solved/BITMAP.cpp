#include<iostream>
#include<queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n,m; cin >> n >> m;
		//vis == 0 means not visited
		//vis > 0 means depth is vis-1
		char ch;
		int vis[n*m]={0};
		//multisource bfs
		//push each of the source in queue at beginning
		//rest is same
		queue<int> q;
		for(int i=0; i<n*m; i++){
			cin >> ch;
			if(ch=='1') {
				q.push(i);
				vis[i] = 1;
			}
		}

		auto visit = [&](int i, int j, int u){
			int k = i*m+j;
			if(vis[k]>0) return;
			q.push(k);
			vis[k] = vis[u]+1;
		};

		while(!q.empty()){
			int u = q.front();
			q.pop();
			int i = u/m, j = u%m;
			if(i-1>=0) visit(i-1, j, u);
			if(j-1>=0) visit(i, j-1, u);
			if(i+1<n) visit(i+1, j, u);
			if(j+1<m) visit(i, j+1, u);
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << vis[i*m+j]-1 << " ";
			}
			cout << "\n";
		}

	}
	return 0;
}