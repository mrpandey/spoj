#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int a[2000][2001];

int main(){
	cin.tie(NULL);
	int t; cin >> t;
	for(int k=1; k<=t; k++){
		int n, m, x, y;
		cin >> n >> m;
		memset(a, 0, 2000*2001*sizeof(int));
		for(int i=0; i<m; i++){
			cin >> x >> y;
			x--; y--;
			a[x][a[x][0]+1] = y;
			a[y][a[y][0]+1] = x;
			a[x][0]++;
			a[y][0]++;
		}
		queue<int> q;
		//vis=0 not visited
		//vis=1 male parity
		//vis=2 female parity
		int vis[n] = {0};
		q.push(x);
		vis[x] = 1;

		bool flag=true;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int i=1; i<=a[u][0]; i++) {
				int v = a[u][i];
				if(!vis[v]){
					q.push(v);
					vis[v] = 3 - vis[u];
				}
				else if(vis[v]==vis[u]) {
					flag=false;
					break;
				}
			}
			if(!flag) break;

			if(q.empty()){
				for(int i=0; i<n; i++){
					if(!vis[i]) {
						q.push(i);
						vis[i] = 1;
						break;
					}
				}
			}
		}

		cout << "Scenario #" << k << ":\n";
		if(flag)
			cout << "No suspicious bugs found!\n";
		else
			cout << "Suspicious bugs found!\n";
	}
	return 0;
}