#include<bits/stdc++.h>
using namespace std;
int dp[301][301], arr[301], n;

int solve(int idx,int tar){
    if(tar == 0) return 1;
    if(tar < 0) return 0;

    int sum = 0;
    for(int i = idx; i<n; i++){
        sum += (dp[i][tar-arr[i]]==-1? solve(i, tar-arr[i]): dp[i][tar-arr[i]]);
    }

    return dp[idx][tar] = sum;
}

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--){
        int tar; cin>>n;
        for(int i=0; i<n; i++) cin>>arr[i];
        cin>>tar;
        memset(dp,-1,sizeof(dp));
        cout << solve(0,tar) << '\n';
    }

    return 0; 
}