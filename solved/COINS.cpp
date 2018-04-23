#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

unordered_map<long long, long long> mp;

long long rec(long long n){
	if(n<4) return n;
	if(mp.find(n)!=mp.end()) return mp[n];
	mp[n] = max(n, rec(n/2)+rec(n/3)+rec(n/4));
	return mp[n];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	while(cin >> n){
		cout << rec(n) << "\n";
	}
	return 0;
}