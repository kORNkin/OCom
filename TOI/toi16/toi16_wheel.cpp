#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, t, ans = 1e18, _lcm[10];
string s[10];

void solve(ll cur, ll idx){
    if(idx == n + 1) { 
        if(cur) ans = min(ans, cur); 
        return; 
    }
    for(ll p = cur; p < _lcm[idx] && p < ans; p += _lcm[idx - 1]){
        if(s[idx][p % s[idx].size()] - '0' == t) solve(p, idx + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;
    _lcm[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        ll sz = s[i].size();
        _lcm[i] = (_lcm[i - 1] * sz) / __gcd(_lcm[i - 1], sz);
    }

    solve(0, 1);

    cout << ans;

    return 0;
}