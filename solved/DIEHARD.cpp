#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int memo[1001][1251];

int rec(int h, int a){
	if(h<=0 || a<=0) return -1;
	if(memo[h][a]==-1){
	 memo[h][a] = max(2+rec(h-17, a+7), 2+rec(h-2, a-8));
	}
	return memo[h][a];
}


int main(){
	cin.tie(NULL);
	int t; cin >> t;
	int a, h;
	int time1, time2;
	memset(memo, -1, sizeof(memo));
	while(t--){
		cin >> h >> a;
		if(h<=0 || a<=0) {cout << "0\n"; continue;}
		cout << rec(h, a) << "\n";
	}
	return 0;
}
