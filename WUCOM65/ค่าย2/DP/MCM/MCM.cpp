#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];

int MCM(int arr[],int i,int j){
    if(i>=j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int mn=1e9;
    for(int k=i;k<j;k++){
        mn = min(mn, MCM(arr, i,k) + MCM(arr, k+1, j) + arr[i-1]*arr[k]*arr[j]);
    }

    return dp[i][j] = mn;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) 
            cin>>arr[i];
        memset(dp,-1,sizeof(dp));
        cout << MCM(arr,1,n-1) << '\n';
    }

	return 0;
}