#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100001], dp[100001]; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];

    int mx=0;
    for(int i=3; i<=n; i++){
        dp[i] = arr[i];
        for(int j=i-3; j>=1 && j>=i-6; j--){
            dp[i]=max(dp[i], arr[i] + dp[j]);
        }
        mx = max(mx,dp[i]);
    }
    cout << mx ;

    return 0;
}
