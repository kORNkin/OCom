/*
Author: kornkin.png
Algor: MCM? (top-down)
too easy for TOI but on that situation, IDK why I couldn't beat this.
*/
#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

long long n, k, d, ans;
long long arr[301], qs[301];
long long dp[301][301][10];

long long solve(int l, int r, int lv){
    if(lv == 1) {
        return 1;
    }

    if(dp[l][r][lv] != -1) return dp[l][r][lv];
    long long a, b;
    dp[l][r][lv] = 0;
    for(int i = l; i < r; i++){
        if(abs(qs[i] - qs[l - 1] - qs[r] + qs[i]) <= d){
            a = solve(l, i, lv - 1) % M; 
            b = solve(i + 1, r, lv - 1) % M;
            if(a && b){
                dp[l][r][lv] += a * b;
                dp[l][r][lv] %= M;
            }
        }
    }

    return dp[l][r][lv];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> d;
    for(int i = 1; i <= n; i++) 
        cin >> arr[i], qs[i] = qs[i - 1] + arr[i];

    memset(dp, -1, sizeof(dp));
    cout << solve(1, n, k);

    return 0;
}