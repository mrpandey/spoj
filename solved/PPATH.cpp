#include<iostream>
#include<queue>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//sieve[i]=0 means prime, 1 means composite
	int sieve[10000] = {0};
	sieve[0] = sieve[1] = 1;
	for(int i=2; i<10000; i++){
		if(sieve[i]) continue;
		for(int j=2*i; j<10000; j+=i){
			sieve[j] = 1;
		}
	}
	
	int t; cin >> t;
	while(t--){
		int p1, p2; cin >> p1 >> p2;
		if(p1==p2) {cout << 0 << "\n"; continue;}

		//bfs
		int vis[10000] = {0}, depth[10000]={0};
		queue<int> q;
		q.push(p1);
		vis[p1] = 1;
		bool flag = true;

		while(!q.empty() && flag){
			int u = q.front();
			q.pop();

			int digu[4]={0};
			digu[0] = u%10; digu[1] = (u/10)%10;
			digu[2] = (u/100)%10; digu[3] = (u/1000)%10;

			for(int i=0, fact=1; i<4 && flag; i++, fact*=10){
				for(int j=0; j<10 && flag; j++){
					int v = u - digu[i]*fact + j*fact;
					if(v>1000 && !sieve[v] && !vis[v]) {
						q.push(v);
						vis[v] = 1;
						depth[v] = depth[u]+1;
						if(v==p2) flag = false;
					}
				}
			}
		}
		cout << depth[p2] << "\n";
	}
	return 0;
}