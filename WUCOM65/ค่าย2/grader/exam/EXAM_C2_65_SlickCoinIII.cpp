#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)
        cin>>arr[i];

    int mn = arr[1];

    int dp1[n+2],dp2[n+2];
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));

    for(int i=2;i<=n;i++){
        dp1[i] = max(dp1[i-1], arr[i] - mn);
        mn = min(arr[i],mn);
    }

    int mx = arr[n];
    for(int i=n-1;i>=1;i--){
        dp2[i] = max(dp2[i+1], mx - arr[i]);
        mx = max(arr[i],mx);
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, dp1[i]+dp2[i]);
    }
    cout << ans;

    return 0;
}
