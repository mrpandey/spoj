#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

int sqn, ans=0;
unordered_map<int, int> cnt;

bool sorti(vector<int> &q1, vector<int> &q2){
	return q1[0]<q2[0];
}

bool sortMo(vector<int> &q1, vector<int> &q2){
	if(q1[1]/sqn == q2[1]/sqn) return q1[2]<q2[2];
	return q1[1]<q2[1];
}

void add(int num){
	cnt[num]++;
	if(cnt[num]==1) ans++;
}

void rem(int num){
	cnt[num]--;
	if(cnt[num]==0) ans--;
}

int main(){
	cin.tie(NULL);
	int n, q; cin >> n;
	int a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	cin >> q;
	vector<vector<int> > dq(q, vector<int>(4, 0));
	for(int i=0; i<q; i++){
		dq[i][0] = i;
		cin >> dq[i][1] >> dq[i][2];
	}
	sqn = floor(sqrt(n));
	sort(dq.begin(), dq.end(), sortMo);

	int curL=0, curR=0;

	for(int i=0; i<q; i++){
		int l=dq[i][1], r=dq[i][2];

		while(curL>l) add(a[curL--]);
		while(curR<r) add(a[curR++]);
		while(curL<l) rem(a[curL++]);
		while(curR>r) rem(a[curR--]);

		dq[i][3] = ans;
	}

	sort(dq.begin(), dq.end(), sorti);
	for(int i=0; i<q; i++) cout << dq[i][3] << "\n";
	return 0;
}
