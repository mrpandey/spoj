#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int size = sqrt(1e9) + 1;
    //notprime[i]=0 iff i is prime
    int notprime[size] = {0};
    notprime[0] = notprime[1] = 1;
    vector<int> primes;
    for(int i=2; i<size; i++){
        if(notprime[i]) continue;
        for(int j=2*i; j<size; j+=i)
            notprime[j] = 1;
        primes.push_back(i);
    }
    
    int t; cin >> t;
    while(t--){
        int m, n; cin >> m >> n;
        //arr[i]=0 iff m+i is prime
        int arr[n-m+1] = {0};
        if(m==1) arr[0] = 1;
        for(int p:primes){
            //j is first no. in [m,n] div by p
            int j = (m%p==0) ? m : m+p-m%p;
            for(; j<=n; j+=p)
                if(j!=p) arr[j-m] = 1;
        }
        for(int i=0; i<n-m+1; i++){
            if(!arr[i]){
                cout << m+i << "\n";
            }
        }
        cout << "\n";
    }
    
    return 0;
}