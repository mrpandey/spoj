#include<iostream>
#include<climits>
#include<cstring>

using namespace std;

struct result {
	long long sum, preSum, suffSum, subSum;
	result(long long a, long long b, long long c, long long d){
		sum=a; preSum=b, suffSum=c, subSum=d;
	}
};

long long max(long long a, long long b){return a<b?b:a;}
long long max(long long a, long long b, long long c){return max(a, max(b,c));}

long long a[100000], totalSum[400000], maxSum[400000], maxSuffSum[400000], maxPreSum[400000];

void build(long long nd, long long s, long long e){
	if(s==e){
		totalSum[nd] = maxSum[nd] = maxSuffSum[nd] = maxPreSum[nd] = a[s];
	}
	else{
		//lc is left child, rc is right child
		long long mid = (s+e)/2, lc = 2*nd+1, rc = 2*nd+2;
		build(lc, s, mid);
		build(rc, mid+1, e);

		totalSum[nd] = totalSum[lc] + totalSum[rc];
		maxPreSum[nd] = max( maxPreSum[lc], totalSum[lc] + maxPreSum[rc] );
		maxSuffSum[nd] = max( maxSuffSum[rc], totalSum[rc] + maxSuffSum[lc] );
		maxSum[nd] = max( maxSum[lc], maxSum[rc], maxSuffSum[lc] + maxPreSum[rc] );
		maxSum[nd] = max( maxSum[nd], maxPreSum[nd], maxSuffSum[nd] );
	}
}

result query(long long nd, long long s, long long e, long long l , long long r){

	if(e<l || s>r) return result(LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);

	if(l<=s && e<=r) return result(totalSum[nd], maxPreSum[nd], maxSuffSum[nd], maxSum[nd]);

	long long mid = (s+e)/2, lc = 2*nd+1, rc = 2*nd+2;

	if(l>mid) return query(rc, mid+1, e, l, r);
	if(r<=mid) return query(lc, s, mid, l, r);

	result lq = query(lc, s, mid, l, r);
	result rq = query(rc, mid+1, e, l, r);

	long long sum = lq.sum + rq.sum;
	long long preSum = max( lq.preSum, lq.sum + rq.preSum );
	long long suffSum = max( rq.suffSum, rq.sum + lq.suffSum );
	long long subSum = max( lq.subSum, rq.subSum, lq.suffSum + rq.preSum );
	subSum = max(preSum, suffSum, subSum);

	return result(sum, preSum, suffSum, subSum);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long t; cin >> t;
	while(t--){
		long long n, m; cin >> n;
		for(long long i=0; i<n; i++) cin >> a[i];
		memset(totalSum, 0, 4*n*sizeof(long long));
		memset(maxSum, 0, 4*n*sizeof(long long));
		memset(maxPreSum, 0, 4*n*sizeof(long long));
		memset(maxSuffSum, 0, 4*n*sizeof(long long));
		build(0, 0, n-1);
		cin >> m;
		while(m--){
			long long x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			x1--; y1--; x2--; y2--;

			if(x1==x2 && y1==y2){
				cout << query(0, 0, n-1, x1, y1).subSum << "\n";
				continue;
			}

			result x1y1 = query(0, 0, n-1, x1, y1);
			result x2y2 = query(0, 0, n-1, x2, y2);
			
			if(y1<x2){
				long long total = query(0, 0, n-1, y1, x2).sum;
				cout << x1y1.suffSum + total + x2y2.preSum - a[x2] - a[y1] << "\n";
				continue;
			}
			else if(y1==x2){
				cout << max(x1y1.suffSum, x2y2.preSum, x1y1.suffSum + x2y2.preSum -a[x2]) << "\n";
				continue;
			}

			result x1x2 = query(0, 0, n-1, x1, x2);
			result y1y2 = query(0, 0, n-1, y1, y2);

			long long ans1=0, ans2=0;

			if(x1==x2){
				ans1 = x1y1.suffSum + y1y2.preSum - a[y1];
				ans2 = x1y1.subSum;
			}
			else if(y1==y2){
				ans1 = x1x2.suffSum + x2y2.preSum - a[x2];
				ans2 = x2y2.subSum;
			}
			else {
				ans1 = x1x2.suffSum + x2y2.preSum - a[x2];
				ans2 = x1y1.suffSum + y1y2.preSum - a[y1];
				long long ans3 = query(0, 0, n-1, x2, y1).subSum;
				ans2 = max(ans2, ans3);
			}

			cout << max(ans1, ans2) << "\n";
		}
	}
	return 0;
}