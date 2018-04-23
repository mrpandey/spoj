#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	if(n-m!=1) {cout << "NO\n"; return 0;}
	vector<vector<int> > adj(n, vector<int>());
	int u, v;
	for(int i=0; i<m; i++){
		cin >> u >> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	int comp=1;
	queue<int> q;
	vector<bool> vis(n, false);
	q.push(0);
	while(!q.empty()){
		int u = q.front();
		vis[u] = true;
		q.pop();
		for(int i=0; i<adj[u].size(); i++){
			v = adj[u][i];
			if(vis[v]) continue;
			q.push(v);
		}
	}
	for(int i=0; i<n; i++){
		if(!vis[i]){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}