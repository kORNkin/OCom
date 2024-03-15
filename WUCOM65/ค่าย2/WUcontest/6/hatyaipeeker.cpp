#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ull n,t,k;
vector<pair<ll,ll>> g;

ull dis(pair<ll,ll> a, pair<ll,ll> b){
    return (ull)abs(a.first-b.first)+abs(a.second-b.second);
}

ull solve(ull l,ull r){
    if(l>=r) return 1e18;

    ull m=(l+r)>>1;

    ull d = min(solve(l,m),solve(m+1,r));

    l = max(0ull,l-200);
    r = min(n-1,r+200);

    for(ll i=l;i<=r;i++){
        if(i==m) continue;
        d = min(d,dis(g[i],g[m]));
    }
    return d;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>t>>k;
    for(ll i=0;i<n;i++){
        ll x,y; cin>>x>>y;
        g.push_back({x,y});
    }
    sort(g.begin(),g.end(), [&](pair<ll,ll> a, pair<ll,ll> b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });

    ull x = solve(0,n-1);
    cout << x << '\n';
    if(x*t <= k) cout << " YES TIME = ";
    else cout << "NO TIME = ";
    cout << x*t;

    return 0;
}
