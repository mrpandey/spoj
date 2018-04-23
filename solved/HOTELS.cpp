#include<iostream>
using namespace std;

int main(){
	long long n, m, sum=0, max=0;
	cin >> n >> m;
	int a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0,j=0; j<n;){
		//cout << "i=" << i << " j=" << j;
		sum += a[j];
		if(sum<=m){
			j++;
			max = sum>max?sum:max;
		}
		else if(i==j){
			sum = 0;
			i = ++j;
		}
		else {
			while(i<=j && sum>m){
				sum -= a[i++];
			}
			max = sum>max?sum:max;
			j++;
		}
		//cout << " sum=" << sum << " max=" << max << "\n";
	}
	cout << max << "\n";
	return 0;
}