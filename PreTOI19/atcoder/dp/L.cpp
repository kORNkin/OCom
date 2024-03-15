#include<bits/stdc++.h>
using namespace std;

int n;
long long arr[3000], dp[3000][3000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0 ; i < n; i++) cin >> arr[i];

    for(int l = n - 1; l >= 0; l--){
        for(int r = l; r < n; r++){
            if(l == r) dp[l][r] = arr[l];
            else {
                dp[l][r] = max(arr[l] - dp[l + 1][r], arr[r] - dp[l][r - 1]);
            }
        }
    }
    cout << dp[0][n - 1];

    return 0;
}
