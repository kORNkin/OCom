#include<bits/stdc++.h>
using namespace std;
struct Bee{
    int val, cnt;
};
int m, n, ans, cnt;
int arr[1001][1001];
Bee dp[1001][1001];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
   
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for(int j = 0; j < n; j++) dp[0][j] = {arr[0][j],1};
    for(int i = 1; i < m; i++){
        for(int j = 0; j < n; j++){
            int c = (i&1? 1: -1);
            if(dp[i-1][j].val == dp[i-1][j+c].val){
                dp[i][j].val = arr[i][j] + dp[i-1][j].val;
                dp[i][j].cnt = dp[i-1][j].cnt + dp[i-1][j+c].cnt;
            }else {
                dp[i][j].val = max(dp[i-1][j].val, dp[i-1][j+c].val) + arr[i][j];
                if(dp[i][j].val == dp[i-1][j].val + arr[i][j]) 
                    dp[i][j].cnt = dp[i-1][j].cnt;
                else dp[i][j].cnt = dp[i-1][j+c].cnt;
            }
        }
    }

    for(int j = 0; j < n; j++) ans = max(ans, dp[m-1][j].val);
    for(int j = 0; j < n; j++) if(ans == dp[m-1][j].val) cnt += dp[m-1][j].cnt;
    cout << ans << ' ' << cnt;

    return 0;
}