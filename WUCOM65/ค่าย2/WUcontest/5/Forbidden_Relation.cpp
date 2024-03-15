#include<bits/stdc++.h>
using namespace std;
bool vis[100001];
int dp[100001][4][2];
int n;
long long solve(int k,int ch,int arr[]){
    if(k > n) return 0;
    if(dp[k][arr[k]][vis[k-1]]) return dp[k][arr[k]][vis[k-1]];
    if(!arr[k]) return solve(k+1,1,arr);
    
    long long a=0, b=0;
    b = solve(k+1,0,arr);
    if(arr[k]==1){
        if(k==n || !vis[k+1]){
            vis[k]=1;
            vis[k+1]=1;
            a = solve(k+2,1,arr) + 1;
            vis[k+1]=0;
            vis[k]=0;
        }
    }else if(arr[k]==2){
        if((k==n && !vis[k-1]) || (k==1 && !vis[k+1]) || (!vis[k-1] && !vis[k+1])){
            vis[k]=1;
            vis[k+1]=1;
            a = solve(k+2,1,arr) + 1;
            vis[k+1]=0;
            vis[k]=0;
        }
    } else if(arr[k]==3){
        if(k==1 || !vis[k-1]){
            vis[k]=1;
            a = solve(k+1,1,arr) + 1;
            vis[k]=0;
        }
    }
    //return max(a,b);
    if(a < b){
        return dp[k][arr[k]][0] = b;
    } else if(a > b) return dp[k][arr[k]][1] = a;
    else return dp[k][arr[k]][1] = dp[k][arr[k]][0] = a;
    
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

    cin>>n;
    int arr[n+5]; 
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }

    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    cout << solve(1,0,arr);

    return 0;
}
/*
8
3 1 3 1 3 1 3 3

6
1 1 1 1 1 1 
*/