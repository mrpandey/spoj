#include<iostream>
#include<map>

using namespace std;

int main(){
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cin.ignore();
		map<string, int> cnt;
		string s;
		for(int i=0; i<n; i++){
			getline(cin, s);
			cnt[s]++;
		}
		
		for(auto it=cnt.begin(); it!=cnt.end(); it++){
			cout << it->first << " " << it->second << "\n";
		}
		cout << "\n";
	}
	return 0;
}