#include<iostream>

using namespace std;

long long ans;

struct node {
	//rc = no. of nodes in right subtree
	//lc = no. of nodes in left subtree
	int val, rc, lc;
	node *l, *r;
	node(int a=0, int b=0, int c=0): val(a), rc(b), lc(c) {
		l = NULL;
		r = NULL;
	}
};

void insert(node *root, node *p){
	if(root->val < p->val){
		(root->rc)++;
		if(root->r) insert(root->r, p);
		else root->r = p;
	}
	else {
		(root->lc)++;
		ans += root->rc + 1;
		if(root->l) insert(root->l, p);
		else root->l = p;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n, x; cin >> n;
		if(n<=1) {cout << "0\n"; continue;}
		cin >> x;
		node *root = new node(x);
		ans = 0;
		for(int i=1; i<n; i++){
			cin >> x;
			node *p = new node(x);
			insert(root, p);
		}
		cout << ans << "\n";
	}
	return 0;
}