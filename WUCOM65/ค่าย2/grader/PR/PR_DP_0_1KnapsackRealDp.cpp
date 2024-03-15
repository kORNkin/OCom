/* Bottom Up (best solution *time and *space)
#include <bits/stdc++.h>
using namespace std;
struct Obj{
    int v,w;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while(T--){
        int n,wx; cin>>n>>wx;
        Obj arr[n+1]; 
        for(int i=1;i<=n;i++) cin>>arr[i].v;
        for(int i=1;i<=n;i++) cin>>arr[i].w;
        int dp[n+1][wx+1];
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=wx;j++){
                if(j < arr[i].w) {
                    dp[i][j] = dp[i-1][j];
                }else {
                    dp[i][j] = max(dp[i-1][j] ,arr[i].v + dp[i-1][j-arr[i].w]);
                }
            }
        }
        cout << dp[n][wx] << '\n';
    }

    return 0;
}
*/

// Top Down 
#include <bits/stdc++.h>
using namespace std;
struct Obj{
    int v,w;
};
int n,wx; 
int dp[1001][1001];
Obj arr[1001];

int solve(int i,int w){
    if(w==0) return 0;
    if(i > n) return 0;
    if(dp[i][w]) return dp[i][w];

    if(arr[i].w > w) return dp[i][w] = solve(i+1,w);
    return dp[i][w] = max(solve(i+1,w),arr[i].v + solve(i+1,w-arr[i].w));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while(T--){
        cin>>n>>wx;
        for(int i=1;i<=n;i++) cin>>arr[i].v;
        for(int i=1;i<=n;i++) cin>>arr[i].w;
        
        cout << solve(1,wx) << '\n';
    }

    return 0;
}
