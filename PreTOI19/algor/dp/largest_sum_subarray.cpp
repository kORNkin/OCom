#include<bits/stdc++.h>
using namespace std;
int dp[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, mx=-1e9, x; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        dp[i] = max(x, dp[i-1]+x);
        mx = max(dp[i],mx);
    } 
    cout << mx;

    return 0;
}