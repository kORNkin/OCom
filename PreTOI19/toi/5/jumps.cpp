#include<bits/stdc++.h>
using namespace std;
int arr[30001];
int dp[60060];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,K; cin>>N>>K;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        dp[arr[i]]++;
    }
    for(int i=1;i<=60000;i++)
        dp[i]+=dp[i-1];
    int mx=0;
    for(int i=1;i<=N;i++){
        mx = max(mx,dp[min(60000,arr[i]+K)]-dp[arr[i]]);
    }
    cout << mx;

    return 0;
}
/*
5 2
1 2 3 4
*/