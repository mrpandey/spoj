#include<iostream>
using namespace std;

int main(){
	cin.tie(NULL);
	int l;
	while(cin>>l){
		string s, t;
		cin >> s >> t;
		int n=t.size();
		if(l>n) continue;
		//lps[i] gives length of longest proper prefix
		//of s[0..i] which is also suffix of s[0..i]
		int lps[l] = {0};
		for(int j=0, i=1; i<l;){
			if(s[j]==s[i]) {
				lps[i++] = ++j;
			}
			else if(j==0){
				lps[i++] = 0;
			}
			else {
				j = lps[j-1];
			}
		}
		int i=0, j=0, ctr=0;
		while(i<n){
			if(s[j]==t[i]){
				i++;
				j++;
			}
			if(j==l){
				cout << i-l << "\n";
				ctr++;
				j = lps[j-1];
			}
			else if(i<n && s[j]!=t[i]){
				if(j>0) j = lps[j-1];
				else i++;
			}
		}
		if(ctr) cout << "\n";
	}
	return 0;
}