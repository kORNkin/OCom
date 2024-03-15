#include<bits/stdc++.h>
using namespace std;
const int N = 1<<8;
int dp[N], arr[10001];
int n, k;

int main(){
    ios_base::sync_with_stdio(0);

    cin >> n >> k;

    memset(dp, 0x3f3f3f3f, sizeof(dp));

    for(int i = 0; i < n; i++){
        int b = 0; cin >> arr[i];
        for(int j = k - 1; j >= 0; j--){
            int x; cin >> x;
            if(x&1) b |= (1<<j);
        }
        dp[b] = min(dp[b],arr[i]);
    }

    for(int l = 0; l < (1<<k); l++){
        for(int j = 0; j <= l; j++){
            if(dp[j] == 0x3f3f3f3f) continue;
            for(int i = 0; i <= j; i++){
                if(dp[i] == 0x3f3f3f3f) continue;
                if((i|j) == l){
                    dp[l] = min(dp[l], dp[j] + dp[i]);
                }
            }
        }
    }
    cout << dp[(1<<k)-1];

    return 0;
}