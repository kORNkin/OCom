#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, qs, mn = 1e18;
pair<ll, ll> box[500001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> box[i].second, mn = min(mn, box[i].second);
    for(int i = 1; i <= n; i++) cin >> box[i].first;

    sort(box + 1, box + 1 + n);

    for(int i = 2; i <= n; i++) qs += box[i].first - box[1].first;
    
    ll ans = box[1].first, ans_cnt = qs;
    for(int i = 2; i <= n; i++){
        if(box[i].first > mn) break;
        qs -= (box[i].first - box[i - 1].first) * n - box[i - 1].second;
        if(qs < ans_cnt){
            ans = box[i].first;
            ans_cnt = qs;
        }
    }

    cout << ans << ' ' << ans_cnt;

    return 0;
}