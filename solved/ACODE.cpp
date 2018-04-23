#include<iostream>

using namespace std;

//recursive solution
int decodings(string &s, int n){
	if(n<1) return 1;
	if(s[n]=='0') return decodings(s, n-2);
	int lastTwo = (s[n-1]-'0')*10 + (s[n]-'0');
	if(s[n-1]=='0' || lastTwo>26) return decodings(s, n-1);
	return decodings(s, n-1) + decodings(s, n-2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string s;
		cin >> s;
		if(s[0]=='0') break;
		//a and b are decodings till i-2 and i-1 resp.
		int n = s.size(), a=0, b=1;
		//int ans = decodings(s, s.size()-1);
		//dynamic programming solution
		for(int i=0; i<n;){
			if(i+1<n && s[i+1]=='0') {a=b; i+=2;}
			else if(i>0 && s[i-1]=='0') {i++;}
			else if(i>0 && ( (s[i-1]-'0')*10 + (s[i]-'0') > 26 ) ) {a=b; i++;}
			else {b=a+b; a=b-a; i++;}
		}
		cout << b <<"\n";
	}
	return 0;
}