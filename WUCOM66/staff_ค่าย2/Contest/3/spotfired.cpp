#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q; cin >> q;
    while(q--){
        ll n; cin >> n;
        
        ll l = 0, r = n;
        while(l < r){
            ll m = (l + r) >> 1;

            ll cnt = m, k = m;
            while(k){
                k /= 10;
                cnt += k;
            }

            if(cnt >= n) r = m;
            else l = m + 1;
        } cout << l << ' ';
    }

    return 0;
}
