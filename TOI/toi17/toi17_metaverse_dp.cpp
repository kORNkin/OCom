#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;

struct P{
    int x, y;
    int operator - (P &r){
        return abs(x - r.x) + abs(y - r.y);
    }
};

int n, m, k, p, dp[20010][20]; // dp[k][p] 
P g[20010], ge[20010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> p;
    for(int i = 0; i < k; i++){
        int xs, ys, xe, ye; 
        cin >> xs >> ys >> xe >> ye;
        g[i] = {xs, ys};
        ge[i] = {xe, ye};
    }

    for(int i = 0; i < k; i++) dp[i][1] = g[i].x + g[i].y - 2;
    for(int pp = 2; pp <= p; pp++){
        for(int i = 0; i < k; i++){
            dp[i][pp] = 1e9;
            for(int j = 0; j < k; j++){
                if(i == j) continue;
                dp[i][pp] = min(dp[i][pp], dp[j][pp-1] + (ge[j] - g[i]));
            }
        }
    }

    int ans = n + m - 2, ansp = 0;
    for(int i = 1; i <= p; i++){
        for(int j = 0; j < k; j++){
            if(ans > dp[j][i] + n + m - ge[j].x - ge[j].y) {
                ans = dp[j][i] + n + m - ge[j].x - ge[j].y;
                ansp = i;
            }
        }
    }

    cout << ans << ' ' << ansp;

    return 0;
}