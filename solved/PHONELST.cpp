#include<iostream>
#include<string>

using namespace std;

struct Node {
	bool isEnd;
	Node* alph[10];
	Node(){
		isEnd = false;
		for(int i=0; i<10; i++) alph[i]=NULL;
	}
};

int main(){
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){

		int n; cin >> n;
		Node *root = new Node();
		string s;
		bool isConsistent = true;

		while(n--){
			cin >> s;
			Node *p = root;

			for(int i=0; i<s.size(); i++){
				int j = s[i]-'0';
				if(p->alph[j] && i==s.size()-1) isConsistent=false;
				if(!p->alph[j]) p->alph[j] = new Node();
				if(p->alph[j]->isEnd) isConsistent=false;
				p = p->alph[j];
			}
			p->isEnd = true;
		}
		
		if(isConsistent) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}