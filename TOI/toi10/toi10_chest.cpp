#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n, ans = 1, cnt = 1 , ti = 1, dv = 1, p[] = {2, 3, 5, 7}, pw[4];
vector<pair<ll, ll>> evn;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> m >> n;

    while(m--){
        ll x, s, t;
        cin >> x >> s >> t;
        evn.push_back({s, x});
        evn.push_back({t + 1, -x});
    }

    sort(evn.begin(), evn.end());
    for(int i = 0; i < evn.size() - 1; i++){
        ll s = evn[i].first, x = evn[i].second;

        bool neg = 0; 
        if(x < 0) x = -x, neg = 1;   

        dv = 1;
        for(int j = 0; j < 4; j++){
            while(x > 1 && x % p[j] == 0){
                if(neg) pw[j]--;
                else pw[j]++;
                x /= p[j];
            }
            dv *= pw[j] + 1;
        }      
 
        if(ans < dv){
            ans = dv, cnt = evn[i + 1].first - s;
        } else if(ans == dv) cnt += evn[i + 1].first - s;
    }

    cout << ans << ' ' << cnt;

    return 0;
}