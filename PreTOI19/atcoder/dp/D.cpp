#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, W, dp[100001], v[101], w[101];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> W;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = W; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    
    ll mx = 0;
    for(int j = 0; j <= W; j++) mx = max(dp[j], mx);
    cout << mx;

    return 0;
}