#include<bits/stdc++.h>
#pragma GCC optimize("O3")
const int mod = 1e9+7;
using namespace std;

int n,m,k; 
map<pair<int,int>, pair<int,int>> mp;

long long dp[1001][1001];

bool valid(int x,int y){
    if(x>n || y>m) return 0;
    return 1;
}
long long solve(int x,int y){
    if(dp[x][y]) return dp[x][y];
    if(x == n && y==m ){
        return dp[x][y] = 1;
    }
    if(mp.find({x,y}) != mp.end()) dp[x][y] += solve(mp[{x,y}].first,mp[{x,y}].second)%mod;
    if(valid(x+1,y)) dp[x][y] += solve(x+1,y)%mod;
    if(valid(x,y+1)) dp[x][y] += solve(x,y+1)%mod;
    return dp[x][y]%=mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>k;
    while(k--){
        int a,b,x,y; cin>>a>>b>>x>>y;
        //mp[{a,b}] = {x,y};
        mp[{x,y}] = {a,b};
    }

    //cout << solve(1,1);
    dp[0][0]=0;
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] += dp[i-1][j]%mod + dp[i][j-1]%mod;
            if(mp.find({i,j}) != mp.end()) dp[i][j] += dp[mp[{i,j}].first][mp[{i,j}].second]%mod;
            dp[i][j]%=mod;
        }
    }
    cout << dp[n][m]%mod << '\n';

    return 0;
}