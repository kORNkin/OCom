#include<bits/stdc++.h>
using namespace std;
struct bag{
    int v,w;
} arr[1001];
int n,mxw;
int dp[1001][1001];

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--){
        cin >> n >> mxw;    
        for(int i=0; i<n; i++) cin>>arr[i].v;
        for(int i=0; i<n ;i++) cin>>arr[i].w;
        
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++){
            for(int j=1; j<=mxw; j++){
                if(arr[i].w > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i].w] + arr[i].v);
            }
        }
        cout << dp[n-1][mxw] << '\n';
    }

    return 0; 
}