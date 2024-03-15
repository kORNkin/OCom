#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> arr[32];
long long dp[1001][1001];
long long n,k,c;
long long solve(int i,long long nn){
    if(nn < 0 || i < 0 || nn < arr[i].first) return 1e18;
    if(nn == 0) return 0;
    if(dp[i][nn]) return dp[i][nn];
    long long x = floor(nn / arr[i].first);
    dp[i][nn] = min(x * arr[i].second + solve(i-1, nn-x*arr[i].first), solve(i-1, nn));
    //cout << dp[i][nn] << '\n';
    return dp[i][nn];
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

    cin>>n>>k>>c;
    if(k==0){
        cout << n*c ;
        return 0;
    }
    arr[0].first = 1;
    arr[0].second = c;
    for(int i=1;i<=k;i++){
        cin>>arr[i].first>>arr[i].second;
        arr[i].first = 1<<arr[i].first;
    }
    cout << solve(k,n);

    return 0;
}