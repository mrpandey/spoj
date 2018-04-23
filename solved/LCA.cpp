#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	int sn = 1;
	while(t--){
		int n; cin >> n;
		vector<vector<int> > adj(n, vector<int>());
		//vis==0 not visited
		//vis>0 means depth=vis-1
		int vis[n] = {0}, parent[n] = {0};
		int root = (n*(n-1))/2;
		for(int i=0; i<n; i++){
			int m,x; cin >> m;
			for(int j=0; j<m; j++){
				cin >> x; x--;
				adj[i].push_back(x);
				root -= x;
				parent[x] = i;
			}
		}

		queue<int> q;
		q.push(root);
		vis[root] = 1;
		parent[root] = -1;

		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int i=0; i<adj[u].size(); i++){
				int v = adj[u][i];
				if(vis[v]==0){
					vis[v] = vis[u]+1;
					q.push(v);
				}
			}
		}

		cout << "Case " << sn << ":\n";
		int p; cin >> p;
		for(int i=0; i<p; i++){
			int v, w;
			cin >> v >> w;
			v--; w--;
			while(vis[v]!=vis[w]){
				if(vis[v]>vis[w]) v = parent[v];
				else w = parent[w];
			}
			while(v!=w){
				v = parent[v];
				w = parent[w];
			}
			cout << v+1 << "\n";
		}
		sn++;
	}
	return 0;
}