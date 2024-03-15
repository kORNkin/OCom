#include<bits/stdc++.h>
using namespace std;
struct Z{
    int idx, cur, l, r, s;
    bool operator < (const Z &r) const {
        return cur < r.cur;
    }
};

int n, m, s, l[2001], r[2001], MX; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) cin >> l[i];
    for(int i = 1; i <= n; i++) cin >> r[i];
   
    /*bool vis[n + 1][300001];
    memset(vis, 0, sizeof(vis));
    int dp[n + 1][m + 1][m + 1];
    memset(dp, 127, sizeof(dp));*/
    int mx[n + 2][m + 1][m + 1];
    memset(mx, 0, sizeof(mx));

    priority_queue<Z> pq;
    pq.push({1, 0, m, m, 0});

    while(!pq.empty()){
        Z now = pq.top();
        pq.pop();


        if(mx[now.idx][now.l][now.r] > now.cur) continue;
        mx[now.idx][now.l][now.r] = now.cur;

        if(now.idx > n) {
            MX = max(MX, now.cur);
            continue;
        } 

        
        if(now.s < s) pq.push({now.idx, now.cur, now.r, now.l, now.s + 1});

        //pq.push({now.idx + 1, now.cur, now.l, now.r, now.s}); //skip

        int ll = 0, rr = 0, dmgl = 0, dmgr = 0;
        ll = l[now.idx];
        
        if(r[now.idx] < 0){
            dmgr = r[now.idx];
        }else rr = r[now.idx];

        if(!dmgr && rr) {
            pq.push({now.idx + 1, now.cur + rr + ll, now.l, now.r, now.s}); 
        } else if(now.r + dmgr >= 0) pq.push({now.idx + 1, now.cur + ll, now.l, now.r + dmgr, now.s});
        pq.push({now.idx + 1, now.cur, now.l, now.r, now.s});
    }

    cout << MX;

    return 0;
}
/*
5 10 0
6 5 2 6 8
-11 1 -3 4 -1
*/