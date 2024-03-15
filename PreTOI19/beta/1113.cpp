#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k, sum, ans;
string s;
unordered_map<ll, ll> mp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    cin >> s;
    mp[0] = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R') sum -= k;
        else sum++;

        if(mp[sum]) ans = max(ans, i - mp[sum]);
        else mp[sum] = i;
    }
    cout << ans;

    return 0;
}