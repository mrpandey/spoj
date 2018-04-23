#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int col;
		cin >> col;
		if(!col) break;
		string s;
		cin >> s;
		//string ans('a', s.size());
		int row = s.size()/col;
		for(int k=0; k<s.size(); k++){
			int i=k%row, j=k/row;
			int pos = i%2==0 ? i*col+j : (i+1)*col -j-1;
			cout << s[pos];
			//ans[k] = s[pos];
		}
		cout << "\n";
	}
	return 0;
}