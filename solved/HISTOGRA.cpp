#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> hist(100001, 0);

    int n;
    while(cin >> n){
        if(n==0) break;

        long long ans = 0;
        for(int i=0; i<n; i++) cin >> hist[i];
        hist[n] = 0;

        stack<int> s;
        long long h, j;

        for(int i=0; i<=n; i++){
            while(!s.empty() && hist[s.top()]>=hist[i]){
                h = hist[s.top()];
                s.pop();
                j = s.empty() ? -1 : s.top();
                ans = max(ans, h*(i-j-1));
            }
            s.push(i);
        }

        cout << ans << "\n";
    }
}