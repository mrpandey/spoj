#include<iostream>
#include<cmath>

using namespace std;

long long tree[400000], a[100000];

void build(int nd, int s, int e){
	if(s==e) tree[nd] = a[s];
	else {
		int mid=(s+e)/2, lc=2*nd+1, rc=2*nd+2;
		build(lc, s, mid);
		build(rc, mid+1, e);
		tree[nd] = tree[lc] + tree[rc];
	}
}

long long query(int nd, int s, int e, int l, int r){
	if(r<s || e<l) return 0;
	if(l<=s && e<=r) return tree[nd];
	int mid=(s+e)/2, lc=2*nd+1, rc=2*nd+2;
	return query(lc, s, mid, l, r) + query(rc, mid+1, e, l, r);
}

void update(int nd, int s, int e, int l, int r){
	if(r<s || e<l) return;
	if(tree[nd]==e-s+1) return;
	if(s==e) {
		tree[nd] = a[s] = floor(sqrt(a[s]));
		return;
	}
	int mid=(s+e)/2, lc=2*nd+1, rc=2*nd+2;
	update(lc, s, mid, l, r);
	update(rc, mid+1, e, l, r);
	tree[nd] = tree[lc] + tree[rc];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; int k=0;
	while(cin >> n){
		for(int i=0; i<n; i++) cin >> a[i];
		build(0, 0, n-1);
		int m; cin >> m;
		cout << "Case #" << ++k << ":\n";
		while(m--){
			int i, x, y;
			cin >> i >> x >> y;
			x--; y--;
			if(x>y){
				x = x+y;
				y = x-y;
				x = x-y;
			}
			if(!i) update(0, 0, n-1, x, y);
			else
				cout << query(0, 0, n-1, x, y) << "\n";
		}
		cout << "\n";
	}
	return 0;
}