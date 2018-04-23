#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//perform dfs and
//returns the last vertex u from s,
//and length b/w s and u
vector<int> dfs(vector<vector<int> > &g, int s){
	int n = g.size();
	vector<bool> vis(n, false);
	vector<int> depth(n, 0);
	stack<int> st;
	st.push(s);
	//x is deepest node discovered till now
	//l = d(s,x)
	int x=s, l=0;
	while(st.size()){
		int u = st.top();
		vis[u] = true;
		st.pop();
		for(int i=0; i<g[u].size(); i++){
			int v = g[u][i];
			if(!vis[v]){
				st.push(v);
				depth[v] = depth[u]+1;
				if(depth[v]>l) {x = v; l=depth[v];}
			}
		}
	}
	return {x, l};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<vector<int> > g(n, vector<int>());
	for(int i=1; i<n; i++){
		int u, v; cin >> u >> v;
		g[u-1].push_back(v-1);
		g[v-1].push_back(u-1);
	}
	vector<int> dfs1 = dfs(g, 0);
	vector<int> dfs2 = dfs(g, dfs1[0]);
	cout << dfs2[1] << "\n";
	return 0;
}