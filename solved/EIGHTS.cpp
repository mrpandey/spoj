#include<iostream>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> last3;
	for(int i=1; i<1000; i++){
		if((i*i*i)%1000 == 888)
			last3.push_back(i);
	}
	int t; cin >> t;
	while(t--){
		long long k;
		cin >> k;
		k--;
		if(k<last3.size()){
			cout << last3[k] << "\n";
			continue;
		}
		cout << k/4 << last3[k%4] << "\n";
	}
	return 0;
}