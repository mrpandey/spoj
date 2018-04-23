#include<iostream>
#include<map>

using namespace std;

int main(){
	cin.tie(NULL);
	int n; cin >> n;
	int a[n];
	map<int, int> cnt;
	for(int i=0; i<n; i++) cin >> a[i];
	int k;
	cin >> k;
	for(int i=0; i<k; i++){
		cnt[a[i]]++;
	}
	auto it = cnt.rbegin();
	cout << (*it).first << " ";
	for(int i=k; i<n; i++){
		int x = a[i-k];
		cnt[a[i]]++;
		cnt[x]--;
		if(cnt[x]==0) cnt.erase(x);
		it = cnt.rbegin();
		cout << (*it).first << " ";
	}
	return 0;
}