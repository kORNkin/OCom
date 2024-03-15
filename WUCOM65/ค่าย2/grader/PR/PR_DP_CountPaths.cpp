#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n,m; 
long long dp[101][101];

long long cntPath(int i,int j){
    if(i < 1 || j < 1) return 0;
    if(i == 1 && j == 1) return 1;
    if(dp[i][j]) return dp[i][j]%mod;

    return dp[i][j] = cntPath(i-1,j)%mod + cntPath(i,j-1)%mod;
}

int main(){
    ios_base::sync_with_stdio(0);

    int T; cin>>T;
    while(T--){
        cin>>n>>m;
        memset(dp,0,sizeof dp);
        cout << cntPath(n,m)%mod << '\n';
    }

    return 0;

}