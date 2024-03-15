#include<bits/stdc++.h>
using namespace std;

int t;

int fac_pow(int n, int k){
    int res = 0;
    while(n){
        n /= k;
        res += n;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--){
        int x; cin >> x;
        cout << min(fac_pow(x, 2), fac_pow(x, 5)) << '\n'; 
    }

    return 0;
}
