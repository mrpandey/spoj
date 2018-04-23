#include<iostream>
#include<stack>
#include<unordered_map>

using namespace std;

int main(){
	cin.tie(NULL);
	int t; cin >> t;
	unordered_map<char, int> mp;
	mp['+'] = 1;
	mp['-'] = 2;
	mp['*'] = 3;
	mp['/'] = 4;
	mp['^'] = 5;
	while(t--){
		string s; cin >> s;
		stack<char> st;
		st.push('(');
		for(int i=0; i<=s.size(); i++){
			char ch = (i==s.size()) ? ')' : s[i];
			if(ch>='a' && ch<='z') cout << ch;
			else if(ch=='(') st.push(ch);
			else if(ch==')') {
				while(st.top()!='('){
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
			//now ch must be an operator
			else if(st.empty() || st.top()=='(') st.push(ch);
			else {
				while(!st.empty() && st.top()!='(' && mp[st.top()]>=mp[ch]) {
					cout << st.top();
					st.pop();
				}
				st.push(ch);
			}
		}
		cout << "\n";
	}
	return 0;
}