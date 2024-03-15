#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int arr[1001][1001];
int n,m;
int solve(int i,int j){
    if(i<1 || i>n) return 0;
    if(j==1) return arr[i][j];
    if(dp[i][j]) return dp[i][j];
    
    int ans=0;
    ans = arr[i][j] + max(solve(i-1,j-1),max(solve(i+1,j-1),solve(i,j-1)));

    return dp[i][j] = ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>arr[i][j];
    int mx=0;
    for(int i=1;i<=n;i++){
        mx = max(mx,solve(i,m));
    }
    cout << mx;

	return 0;
}
/*
2 3
1 3 3
2 3 4
*/