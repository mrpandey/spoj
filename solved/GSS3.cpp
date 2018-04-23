#include<iostream>
#include<climits>

using namespace std;

struct result {
	int sum, preSum, suffSum, subSum;
	result(int a, int b, int c, int d){
		sum=a; preSum=b, suffSum=c, subSum=d;
	}
};

int max(int a, int b){return a<b?b:a;}
int max(int a, int b, int c){return max(a, max(b,c));}

int a[50010], totalSum[4*50010], maxSum[4*50010], maxSuffSum[4*50010], maxPreSum[4*50010];

void build(int nd, int s, int e){
	if(s==e){
		totalSum[nd] = maxSum[nd] = maxSuffSum[nd] = maxPreSum[nd] = a[s];
	}
	else{
		//lc is left child, rc is right child
		int mid = (s+e)/2, lc = 2*nd+1, rc = 2*nd+2;
		build(lc, s, mid);
		build(rc, mid+1, e);

		totalSum[nd] = totalSum[lc] + totalSum[rc];
		maxPreSum[nd] = max( maxPreSum[lc], totalSum[lc] + maxPreSum[rc] );
		maxSuffSum[nd] = max( maxSuffSum[rc], totalSum[rc] + maxSuffSum[lc] );
		maxSum[nd] = max( maxSum[lc], maxSum[rc], maxSuffSum[lc] + maxPreSum[rc] );
		maxSum[nd] = max( maxSum[nd], maxPreSum[nd], maxSuffSum[nd] );
	}
}

void update(int nd, int s, int e, int x, int v){
	if(s==e){
		totalSum[nd] = maxSum[nd] = maxSuffSum[nd] = maxPreSum[nd] = v;
	}
	else {
		int mid = (s+e)/2, lc = 2*nd+1, rc = 2*nd+2;
		if(x<=mid) update(lc, s, mid, x, v);
		else update(rc, mid+1, e, x, v);

		totalSum[nd] = totalSum[lc] + totalSum[rc];
		maxPreSum[nd] = max( maxPreSum[lc], totalSum[lc] + maxPreSum[rc] );
		maxSuffSum[nd] = max( maxSuffSum[rc], totalSum[rc] + maxSuffSum[lc] );
		maxSum[nd] = max( maxSum[lc], maxSum[rc], maxSuffSum[lc] + maxPreSum[rc] );
		maxSum[nd] = max( maxSum[nd], maxPreSum[nd], maxSuffSum[nd] );
	}
}

result query(int nd, int s, int e, int l , int r){

	if(e<l || s>r) return result(INT_MIN, INT_MIN, INT_MIN, INT_MIN);

	if(l<=s && e<=r) return result(totalSum[nd], maxPreSum[nd], maxSuffSum[nd], maxSum[nd]);

	int mid = (s+e)/2, lc = 2*nd+1, rc = 2*nd+2;

	if(l>mid) return query(rc, mid+1, e, l, r);
	if(r<=mid) return query(lc, s, mid, l, r);

	result lq = query(lc, s, mid, l, r);
	result rq = query(rc, mid+1, e, l, r);

	int sum = lq.sum + rq.sum;
	int preSum = max( lq.preSum, lq.sum + rq.preSum );
	int suffSum = max( rq.suffSum, rq.sum + lq.suffSum );
	int subSum = max( lq.subSum, rq.subSum, lq.suffSum + rq.preSum );
	subSum = max(preSum, suffSum, subSum);

	return result(sum, preSum, suffSum, subSum);
}

int main(){
	ios::sync_with_stdio(false);
	int n, m; cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	build(0, 0, n-1);
	cin >> m;
	while(m--){
		int t, x, y; cin >> t >> x >> y;
		if(t==0) update(0, 0, n-1, x-1, y);
		else {
			result res = query(0, 0, n-1, x-1, y-1);
			cout << res.subSum << "\n";
		}
	}
	return 0;
}