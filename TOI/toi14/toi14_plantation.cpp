#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct P{
    ll x, y;
    bool operator < (P &r){
        return (x == r.x? y < r.y: x < r.x);
    }
    ll operator - (const P &r){
        return (x - r.x) * (x - r.x) + (y - r.y) * (y - r.y);
    }
    
} p[100001];
int n, r, d, chk;
bool flg;
ll super_close_pair(int l,int r){
    if(flg) return -1;
    if(l >= r) return 1e18;

    int m = (l+r) >> 1;

    ll dis = min(super_close_pair(l,m), super_close_pair(m+1,r));

    l = max(0, l - 4);
    r = min(n - 1, r + 4);

    for(int i = l; i <= r; i++)
        if(i != m) dis = min(dis, p[i] - p[m]);
    
    if(dis < chk){
        flg = 1;
        return -1;
    }

    return dis;
}

void solve(){
    cin >> n >> r >> d;
    chk = (d + (r<<1)) * (d + (r<<1));
    for(int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    sort(p, p+n);

    flg = 0;
    if(super_close_pair(0, n-1) >= chk) cout << "Y\n";
    else cout << "N\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}