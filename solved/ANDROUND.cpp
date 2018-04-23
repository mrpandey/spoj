#include<iostream>
#include<cstring>

using namespace std;

int a[20000], tree[80000];

void build(int nd, int s, int e){
	if(s==e) tree[nd] = a[s];
	else {
		int mid = (s+e)/2, lc=2*nd+1, rc=2*nd+2;
		build(lc, s, mid);
		build(rc, mid+1, e);
		tree[nd] = tree[lc] & tree[rc];
	}
}

int query(int nd, int s, int e, int l, int r){
	if(r<s || e<l) return ~0;
	if(l<=s && e<=r) return tree[nd];
	int mid = (s+e)/2, lc=2*nd+1, rc=2*nd+2;
	int lq = query(lc, s, mid, l, r);
	int rq = query(rc, mid+1, e, l, r);
	return lq & rq;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		for(int i=0; i<n; i++) cin >> a[i];
		memset(tree, 0, 4*n*sizeof(int));
		build(0, 0, n-1);

		if(k > n/2) k = n/2;
		for(int i=0; i<n; i++){
			int l1, r1, l2=-1, r2=-1;
			if(i-k<0){
				l1=0; r1=i;
				l2=n+i-k; r2=n-1;
			}
			else {
				l1=i-k; r1=i;
			}
			int q1 = query(0, 0,n-1, l1,r1) & query(0, 0,n-1, l2,r2);
			
			l2 = r2 = n;
			if(i+k>n-1){
				l1=i; r1=n-1;
				l2=0; r2=i+k-n;
			}
			else{
				l1=i; r1=i+k;
			}
			int q2 = query(0, 0,n-1, l1,r1) & query(0, 0,n-1, l2,r2);

			cout << (q1 & q2) << " ";
		}
		cout << "\n";
	}
	return 0;
}