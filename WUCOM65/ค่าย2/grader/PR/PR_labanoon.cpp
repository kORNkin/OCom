#include<bits/stdc++.h>
using namespace std;
int arr[10001], dp[10001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int x; cin>>x;

    for(int i=1;i<=x;i++){
        dp[i] = arr[i];
        for(int j=1;j<=i/2;j++){
            dp[i] = max(dp[i],dp[i-j]+dp[j]);
        }
    } cout << dp[x];

    return 0;
}