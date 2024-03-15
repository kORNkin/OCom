#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct P{
    ll x, y, z;
    ll m, k, c;
} p[11];

ll N, M, ans = 1e18;
bitset<11> vis;

ll D(P a, P b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z); }

void solve(int idx, ll dis, int m, int k,int c){
    if(min({m, k, c}) >= N) {
        ans = min(ans, dis);
        return ;
    }
    for(int i = 1; i <= M; i++){ 
        if(ans <= dis + D(p[idx], p[i]) || vis[i]) continue;
        vis[i] = 1;
        solve(i, dis + D(p[idx], p[i]), m + p[i].m, k + p[i].k, c + p[i].c);
        vis[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    cin >> N >> p[0].x >> p[0].y >> p[0].z >> M;
    p[0].m = p[0].k = p[0].c = 0;
    for(int i = 1; i <= M; i++) 
        cin >> p[i].x >> p[i].y >> p[i].z >> p[i].m >> p[i].k >> p[i].c;

    solve(0, 0, 0, 0, 0);
    cout << ans;

    return 0;
}