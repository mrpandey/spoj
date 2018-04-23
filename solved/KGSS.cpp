#include<iostream>
#include<climits>

#define M 100000

using namespace std;

struct Node {
	//m1 is max
	//m2 is second max
	int m1, m2;
	Node() {
		m1 = m2 = INT_MIN;
	}
};

int a[M];
Node tree[4*M];

int max(int a, int b){
	return a<b?b:a;
}

/*
void setMax(int nd, int lc, int rc){
	if(tree[lc].m1>=tree[rc].m1){
		tree[nd].m1 = tree[lc].m1;
		tree[nd].m2 = max(tree[lc].m2, tree[rc].m1);
	}
	else {
		tree[nd].m1 = tree[rc].m1;
		tree[nd].m2 = max(tree[rc].m2, tree[lc].m1);
	}
}*/

Node setMax(Node nd1, Node nd2){
	Node ret;
	if(nd1.m1>=nd2.m1){
		ret.m1 = nd1.m1;
		ret.m2 = max(nd1.m2, nd2.m1);
	}
	else {
		ret.m1 = nd2.m1;
		ret.m2 = max(nd2.m2, nd1.m1);
	}
	return ret;
}

void build(int nd, int s, int e){
	if(s==e){
		tree[nd].m1 = a[s];
		return;
	}
	int mid=(s+e)/2, lc=2*nd+1, rc=2*nd+2;
	build(lc, s, mid);
	build(rc, mid+1, e);
	tree[nd] = setMax(tree[lc], tree[rc]);
}

void update(int nd, int s, int e, int i, int x){
	if(i<s || e<i) return;
	if(s==e) {
		tree[nd].m1 = a[s] = x;
		return;
	}
	int mid=(s+e)/2, lc=2*nd+1, rc=2*nd+2;
	update(lc, s, mid, i, x);
	update(rc, mid+1, e, i, x);
	tree[nd] = setMax(tree[lc], tree[rc]);
}

Node query(int nd, int s, int e, int x, int y){
	Node ans;
	if(y<s || e<x) return ans;
	if(x<=s && e<=y) return tree[nd];

	int mid=(s+e)/2, lc=2*nd+1, rc=2*nd+2;
	Node nd1 = query(lc, s, mid, x, y);
	Node nd2 = query(rc, mid+1, e, x, y);
	return setMax(nd1, nd2);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q; cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	build(0, 0, n-1);
	cin >> q;
	int x, y;
	char c;
	while(q--){
		cin >> c >> x >> y;
		x--;
		if(c=='Q') {
			Node ans = query(0, 0, n-1, x, --y);
			cout << ans.m1 + ans.m2 << "\n";
		}
		else update(0, 0, n-1, x, y);
	}
}