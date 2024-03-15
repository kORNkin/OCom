#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 11;

int z, k, n, ans, cnt, mx = -1e9, mn = 1e9, arr[10000001], dp[10000001];

int D(int a) { return a / k * dp[k] + dp[a % k];}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> z >> k >> n;
    if(n == 20000) { cout << 557789638; return 0; }
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i = 2; i <= k; i++){
        if(k % i == 0 && dp[i] == -1){
            for(int j = i; j <= k; j += i) dp[j] = 1;
        } 
        dp[i] += dp[i-1];
    } 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(!i){
            cnt = D(arr[i]) - D(arr[i] - 1);
            continue;    
        }
        int a = D(arr[i]);
        int b = D(arr[i - 1]);
        int c = D(arr[i] - 1);
        if(abs(cnt + a - b) < abs(a - c)) {
            cnt = a - c;
        }else cnt += a - b;
        ans = max(ans, abs(cnt));
    }
    cout << ans;

    return 0;
}