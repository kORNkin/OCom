#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, q, qs[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        ll x; cin >> x;
        qs[i] = qs[i-1] + x;
    }

    /*
    ll mn = 1e18;
    for(int i = n; i >= 1; i--){
        if(qs[i] > mn) qs[i] = mn;
        mn = min(mn, qs[i]);
    }  
    */


    //faster
    for(int i = n - 1; i >= 1; i--){
        qs[i] = min(qs[i], qs[i + 1]);
    }  

    while(q--){
        ll x; cin >> x;
        cout << upper_bound(qs + 1, qs + 1 + n, x) - qs - 1 << '\n';
    }

    return 0;
}