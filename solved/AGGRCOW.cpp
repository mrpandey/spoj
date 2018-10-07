#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, c;
        cin >> n >> c;

        vector<long long> x(n,0);
        for(int i=0; i<n; i++){
            cin >> x[i];
        }

        sort(x.begin(), x.end());

        long long hi = x[n-1]-x[0];
        long long lo = 0;
        long long mid = 0;

        while(lo<hi-1){

            mid = lo + (hi-lo)/2;

            int j=0, ctr=1;
            for(int i=1; i<n && ctr<c; i++){
                if(x[i]-x[j]>=mid) {
                    ctr++;
                    j=i;
                }
            }

            if(ctr==c) lo=mid;
            else hi=mid-1;
        }

        int j=0, ctr=1;
        for(int i=1; i<n && ctr<c; i++){
            if(x[i]-x[j]>=hi) {
                ctr++;
                j=i;
            }
        }
        
        if(ctr==c) cout << hi << "\n";
        else cout << lo << "\n";
    }
}