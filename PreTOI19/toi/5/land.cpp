#include<bits/stdc++.h>
using namespace std;
#define tii tuple<double,int,int>
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,-1,1,1,-1};
double ans=1e9;
double arr[5][5];
bool vis[5][5];
int n,m; 
void solve(double sum,int t){
    if(t==n*m) {
        ans = min(sum,ans);
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j]){
                vis[i][j]=1;
                for(int k=0;k<8;k++)
                    arr[i+dx[k]][j+dy[k]]+=arr[i][j]*0.1;
                
                solve(sum+arr[i][j],t+1);
                for(int k=0;k<8;k++)
                    arr[i+dx[k]][j+dy[k]]-=arr[i][j]*0.1;
                vis[i][j]=0;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    
    memset(arr,0,sizeof(arr));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }

    solve(0,0);
    cout << fixed << setprecision(2) << ans;

    return 0;
}