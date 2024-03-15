/*
Author: kornkin.png
Algor: DP + Binary Search(optional)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Point{
    ll x, y;
    bool operator < (Point &r){
        return (x == r.x ? y < r.y : x < r.x);
    }
    ll operator - (Point &r){
        return abs(x - r.x) + abs(y - r.y);
    }
};
struct N{
    ll n,d;
};

ll n, m;
pair<ll,ll> p[501];
vector<Point> tp;
ll dp[200001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        ll x,y; cin >> x >> y;
        tp.push_back({x,y});
    }

    vector<N> mem[n];
    for(int i = 1; i < n; i++){
        mem[i].push_back({1, tp[i]-tp[0]});
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            for(int k = 1; k < n; k++){
                if(j == k) continue;
                if(mem[j].size() == i) mem[j].push_back({i+1,max(tp[j]-tp[k], mem[k][i-1].d)});
                else mem[j][i].d = min(mem[j][i].d,max(tp[j]-tp[k], mem[k][i-1].d));
            }
        }
    }
    
    ll ans = 0;
    for(int i = 1; i <= m; i++){
        ll x; cin >> x;
        ll l = 1, r = n-1;
        while(l < r){
            ll m = (l+r) >> 1;
            if(mem[n-1][m-1].d > x) l = m+1;
            else r = m; 
        }
        ans += l;
        /*for(auto xx:mem[n-1]) {
            if(x >= xx.d){
                ans += xx.n;
                break;
            }
        }*/
    }  cout << ans;

    return 0;
}