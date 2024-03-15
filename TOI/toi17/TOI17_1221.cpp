/*
Author: kornkin.png
Algor: DP
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long cnt[501][501], dp[501][501];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>q;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        for(int j=1;j<i;j++){
            dp[i][j] = dp[j][i] = arr[i]+arr[j];
            cnt[i][j] = cnt[j][i] = 2;
        }         
        cnt[i][i]=1;
        dp[i][i]=0;
    }

    for(int i=1;i<=m;i++){
        long long u,v,w; cin>>u>>v>>w;
        dp[u][v] = dp[v][u] = w;
        cnt[u][v] = cnt[v][u] = 2;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){ 
                if(dp[i][j] > dp[i][k]+dp[k][j]){
                    dp[i][j] = dp[i][k]+dp[k][j];
                    cnt[i][j] = cnt[i][k]+cnt[k][j];
                }  
            }
        }
    }

    long long u,v;
    while(q--){
        cin>>u>>v;
        cout << dp[u][v] << " " << cnt[u][v] << '\n';
    }

    return 0;
}