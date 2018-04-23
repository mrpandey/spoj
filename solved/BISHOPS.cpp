#include<iostream>
using namespace std;

void subOne(string &s){
	for(int i=s.size()-1; i>=0; i--){
		if(s[i]=='0'){
			s[i] = '9';
		}
		else {
			s[i] = '0'+s[i]-'1';
			break;
		}
	}
	if(s[0]=='0') s.erase(0,1);
}

char multTwo(string &s){
	int cr=0;
	for(int i=s.size()-1; i>=0; i--){
		int sum = 2*(s[i]-'0') + cr;
		if(sum>9) {sum-=10; cr=1;}
		else cr=0;
		s[i] = '0'+sum;
	}
	return '0'+cr;
}

int main(){
	cin.tie(NULL);
	string s;
	while(cin >> s){
		if(s.size()==1 && s[0]=='1') {
			cout << "1\n"; continue;
		}
		subOne(s);
		if(multTwo(s)=='1') cout << "1";
		cout << s << "\n";
	}

	return 0;
}