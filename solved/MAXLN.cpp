#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        long long r;
        cin >> r;

        double ans = (double)(16*r*r+1)/4;
        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << "Case " << i << ": " << ans << "\n";
    }
}