#include<bits/stdc++.h>
using namespace std;
int n, dp[1001][1001];
char arr[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n; 
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(i == j) continue;
            if(arr[i] == arr[j]) dp[i][j] = 1 + dp[i+1][j-1];
            else {
                int mx = 0;
                for(int  k= i; k < j; k++){
                    mx = max(mx, dp[i][k] + dp[k+1][j]);
                } dp[i][j] = mx;
            }
        }
    } 
    cout << dp[0][n-1];

    return 0; 
}