#include<iostream>
#include<stack>

using namespace std;

int main(){
	cin.tie(NULL);
	int n;
	while(cin>>n){
		if(n==0) break;
		stack<int> s;
		int last=0, curr;
		for(int i=0; i<n; i++){
			cin >> curr;
			while(!s.empty() && s.top()==last+1){
				last++;
				s.pop();
			}
			if(curr==last+1) {last++;}
			else s.push(curr);
		}
		while(!s.empty() && s.top()==last+1){
			last++;
			s.pop();
		}
		if(s.empty()) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}