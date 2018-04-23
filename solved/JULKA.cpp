#include<iostream>

using namespace std;

string addStr(const string &a, const string &b){
	string s="";
	int n=a.size(), m=b.size();
	int cr = 0;
	for(int i=n-1, j=m-1; i>=0 || j>=0; i--, j--){
		int ai = a[i]-'0', bj = 0;
		if(j>=0) bj = b[j]-'0';
		int c = (ai+bj+cr)%10;
		cr = (ai+bj+cr)/10;
		s.push_back('0'+c);
	}
	if(cr) s.push_back('0'+cr);
	//note that s[0] is least significant digit
	//s is reverse number
	return s;
}

//divides even number by two
string divStr(string d){
	string s="";
	int n = d.size();
	//d is reverse; d[0] is least signigicant digit
	if(n==1) {s.push_back('0'+(d[0]-'0')/2); return s;}

	int rem=0, i=n-1;
	if(d[i]-'0'==1) {rem=1; i--;}
	for(; i>=0; i--){
		int num = rem*10+(d[i]-'0');
		s.push_back('0'+num/2);
		rem=num%2;
	}
	//this s is okay; s[0] is most significant digit
	return s;
}

string diffStr(string &a, string &b){
	string s="";
	int n=a.size(), m=b.size();
	int cr = 0;
	for(int i=n-1, j=m-1; i>=0 || j>=0; i--, j--){
		int ai = a[i]-'0', bj = 0;
		if(j>=0) bj = b[j]-'0';
		int c = ai-bj-cr;
		if(c<0) {cr=1; c+=10;}
		else {cr=0;}
		s.push_back('0'+c);
	}
	string rev="";
	int i=s.size()-1;
	while(i>=0 && s[i]=='0') i--;
	if(i<0) return "0";
	while(i>=0) rev.push_back(s[i--]);
	return rev;
}

int main(){
	cin.tie(NULL);
	int t=10;
	while(t--){
		string a, b;
		cin >> a >> b;
		//x=(a+b)/2; y=a-x;
		string x = divStr(addStr(a, b));
		//cout << x << endl;
		string y = diffStr(a, x);
		cout << x << "\n" << y << "\n";
	}
	return 0;
}