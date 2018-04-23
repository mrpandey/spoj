#include<iostream>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int s, c; cin >> s >> c;
		vector<vector<int> > seq;
		seq.push_back(vector<int>(s, 0));
		bool isConstSeq = true;
		for(int i=0; i<s; i++) {
			cin >> seq[0][i];
			if(i>0 && seq[0][i]!=seq[0][i-1]) isConstSeq = false;
		}
		//i is index of last sequence
		int i=0;
		while(!isConstSeq){
			isConstSeq = true;
			int n = seq[i].size();
			seq.push_back( vector<int>(n-1, 0) );
			for(int j=0; j<n-1; j++){
				seq[i+1][j] = seq[i][j+1] - seq[i][j];
				if(j>0 && seq[i+1][j] != seq[i+1][j-1]) isConstSeq = false;
			}
			i++;
		}
		//now seq[i] is a constant sequence (might be length 1)
		//insert c copies of seq[i][0] at end
		seq[i].insert(seq[i].end(), c, seq[i][0]);
		i--;
		while(i>=0){
			int n = seq[i].size();
			for(int j=n-1; j<n+c-1; j++){
				seq[i].push_back(seq[i][j]+seq[i+1][j]);
			}
			i--;
		}
		for(int j=seq[0].size()-c; j<seq[0].size(); j++){
			cout << seq[0][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}