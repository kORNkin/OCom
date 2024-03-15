#include<bits/stdc++.h>
using namespace std;
int dp[51];
long long solve(int n){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]) return dp[n];

    return dp[n] = solve(n-1) + solve(n-3) + solve(n-4);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    cout << solve(n);

	return 0;
}