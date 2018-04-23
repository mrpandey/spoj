#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

long long tree[1<<18], lazy[1<<18];

void update(int nd, int s, int e, int l, int r, int v){

	int mid = (s+e)/2, lc=2*nd+1, rc=2*nd+2;

	//lazy update
	//it should be done even if [l,r] and [s,e] don't overlap
	//bcoz parent of nd depends on nd's value
	if(lazy[nd]!=0){
		tree[nd] += lazy[nd]*(e-s+1);
		if(s!=e){
			lazy[lc] += lazy[nd];
			lazy[rc] += lazy[nd];
		}
		lazy[nd] = 0;
	}

	//this thing should come right after lazy update
	if(r<s || e<l) return;

	//[s,e] subset of [l,r]
	if(l<=s && e<=r){
		tree[nd] += (long long)(e-s+1)*v;
		if(s!=e){
			lazy[lc] += v;
			lazy[rc] += v;
		}
		return;
	}

	update(lc, s, mid, l, r, v);
	update(rc, mid+1, e, l, r, v);
	tree[nd] = tree[lc] + tree[rc];
}

long long query(int nd, int s, int e, int l, int r){
	if(r<s || e<l) return 0;

	int mid = (s+e)/2, lc=2*nd+1, rc=2*nd+2;

	if(lazy[nd]!=0){
		tree[nd] += lazy[nd]*(e-s+1);
		if(s!=e){
			lazy[lc] += lazy[nd];
			lazy[rc] += lazy[nd];
		}
		lazy[nd] = 0;
	}

	if(l<=s && e<=r) return tree[nd];

	return query(lc, s, mid, l, r) + query(rc, mid+1, e, l, r);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n, c; cin >> n >> c;
		int sz = ceil(log2(n));
		sz = 1<<(sz+1);
		memset(tree, 0, sz*sizeof(long long));
		memset(lazy, 0, sz*sizeof(long long));
		while(c--){
			int t, p, q, v;
			cin >> t >> p >> q;
			if(t==0){
				cin >> v;
				update(0, 0, n-1, p-1, q-1, v);
			}
			else cout << query(0, 0, n-1, p-1, q-1) << "\n";
		}
	}
	return 0;
}