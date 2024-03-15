#include<bits/stdc++.h>
using namespace std;
int t, n, a[501], dp[501][501];

int solve(int l,int r){
    if(l==r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int mn = 1e9;
    for(int i = l; i<r ;i++){
        mn = min(mn, solve(l,i) + solve(i+1,r) + a[l-1] * a[i] * a[r]);
    }
    return dp[l][r] = mn;
}   

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n; 
        for(int i=0; i<n; i++) cin>>a[i];
        

        // ---------top-down----------
        memset(dp, -1 ,sizeof(dp));
        cout << solve(1,n-1) << '\n';  

        // ---------bottom-up---------
        n--;
        memset(dp, 0 ,sizeof(dp));
        for(int i = n - 1; i >= 1; i--){ // dp from i (n-1 --> 1) and j (i+1 --> n) เพราะ dp แต่ละตัวเกิดจาก dp ล่าง + dp ซ้าย
            for(int j = i + 1; j <= n; j++){
                dp[i][j] = 1e9;
                for(int k=i; k<j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j]);
                    //cout << "i-k: (" << i << "," << k << ") k+1-j: (" << k+1 << "," << j << ")"<< "\n";
                    //cout << "a: " << a[i-1] * a[k] * a[j] << " sum:" << dp[i][j] << '\n';
                }
            }
        }       
        cout << dp[1][n] << '\n';
    
    }

    return 0; 
}