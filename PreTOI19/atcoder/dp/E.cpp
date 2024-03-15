#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, mxW, mxV, w[101], v[101], dp[101][100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> mxW;
    memset(dp, 127, sizeof(dp));
    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i], mxV += v[i];

    for(int i = 0; i <= n; i++) dp[i][0] = 0;

    ll mx = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= mxV; j++){
            if(v[i] <= j) dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
            else dp[i][j] = dp[i - 1][j];
            mx = max(mx, (dp[i][j] <= mxW? j: mx));
        }
    }
    cout << mx;

    return 0;
}