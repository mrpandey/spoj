#include<iostream>

using namespace std;

bool isDig(char a){
	if(a-'0'>=0 && '9'-a>=0) return true;
	return false;
}

int main(){
	cin.tie(NULL);
	int t; cin >> t;
	cin.ignore();
	while(t--){
		cin.ignore();
		string s;
		getline(cin, s);
		int a=0, b=0, c=0, i=0;
		while(isDig(s[i])){
			a *= 10;
			a += s[i]-'0';
			i++;
		}
		if(s[i]!=' ') a=0;
		while(s[i]!=' ') i++;
		i += 3;

		while(isDig(s[i])){
			b *= 10;
			b += s[i]-'0';
			i++;
		}
		if(s[i]!=' ') b=0;
		while(s[i]!=' ') i++;
		i += 3;

		while(i<s.size() && isDig(s[i])){
			c *= 10;
			c += s[i]-'0';
			i++;
		}
		if(i<s.size()) c=0;
		
		if(a==0) a = c-b;
		if(b==0) b = c-a;
		if(c==0) c = a+b;
		cout << a << " + " << b << " = " << c << "\n";
	}
	return 0;
}