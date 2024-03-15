/*
Author: kornkin.png
Algor: DP (MCM)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll int
const int N = 5001;

int n,sq;
ll arr[N], dp[N][N];
ll chp[N][N];

ll F(int l, int r,ll pre){
    if(l >= r) return pre + arr[l];

    if(dp[l][r]) return pre + dp[l][r];

    ll a = pre + arr[l] + F(l+1, r, abs(arr[l]-arr[r]));
    ll b = pre + arr[r] + F(l, r-1, abs(arr[l]-arr[r]));
    dp[l][r] = max(a,b) - pre;
    return max(a,b);

}
ll chop(int l,int r){
    if(l >= r) return chp[l][r] = arr[l];

    ll sum = (dp[l][r]? dp[l][r]: F(l,r,0));
    for(int k = l * n; k < r - l * n; k++){
        sum = max(sum, (chp[l][k]? chp[l][k]: chop(l, k)) + (chp[k+1][r]? chp[k+1][r]: chop(k+1, r)));
    }

    return chp[l][r] = sum;
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i], dp[i][i] = chp[i][i] = arr[i];

    for(int l = n-2; l >= 0 ; l--){
        for(int r = l + 1; r < n; r++){
            dp[l][r] = max(dp[l+1][r] + arr[l], dp[l][r-1] + arr[r]) + abs(arr[l] - arr[r]);
        }
    }

    for(int l = n-2; l >= 0; l--){
        for(int r = l; r < n; r++){
            chp[l][r] = dp[l][r];
            for(int k = l * n; k < r - l * n; k++){
                chp[l][r] = max(chp[l][r] , chp[l][k] + chp[k+1][r]);
            }
        }
    }

    //ll res = chop(0,n-1);
    ll res = chp[0][n-1];

    cout << res;

    return 0;
}
/*
7
6 83 82 88 11 63 8
*/