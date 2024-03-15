#include<bits/stdc++.h>
using namespace std;
struct table{
    int day, val;
} dp[1001][1001];

int n, k, a[1001], b[1001];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    cin >> k >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i == 1) 
            dp[0][i] = {1, a[i]};
        else if(dp[0][i - 1].val + a[i] <= k) 
            dp[0][i] = {dp[0][i-1].day, dp[0][i-1].val + a[i]};
        else dp[0][i] = {dp[0][i-1].day + 1, a[i]};
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        if(i == 1) 
            dp[i][0] = {1, b[i]};
        else if(dp[i-1][0].val + b[i] <= k) 
            dp[i][0] = {dp[i-1][0].day, dp[i-1][0].val + b[i]};
        else dp[i][0] = {dp[i-1][0].day + 1, b[i]};
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int d, v;
            if(b[i] + dp[i-1][j].val > k) 
                d = dp[i-1][j].day + 1, v = b[i];
            else d = dp[i-1][j].day, v = b[i] + dp[i-1][j].val;
            if(a[j] + dp[i][j-1].val > k){
                if(dp[i][j-1].day + 1 == d) v = min(v, a[j]);
                else if(dp[i][j-1].day + 1 < d) d = dp[i][j - 1].day + 1, v = a[j];
            }else {
                if(dp[i][j-1].day == d) v = min(v, a[j] + dp[i][j-1].val);
                else if(dp[i][j-1].day < d) d = dp[i][j - 1].day, v = a[j] + dp[i][j-1].val;
            }
            dp[i][j] = {d, v};
        }
    }
    cout << dp[n][n].day << '\n' << dp[n][n].val;

    return 0;
}