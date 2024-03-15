#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod = 1e9 + 7; 
int n, m;
ll dp[1001][1001]; 
char g[1001][1001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j];
        }
    }
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(g[i][j] == '#') continue;
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= Mod;
        }
    }
    cout << dp[n][m];

    return 0;
}
