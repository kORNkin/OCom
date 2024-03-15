#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long n,m;
long long dp[1001][1001][3];
string s[10001];

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin>>T;
    memset(dp,0,sizeof(dp));
    while(T--){
        cin>>n>>m;

        dp[1][1][0]=1;
        dp[1][1][1]=1;
        dp[1][1][2]=1;

        for(int i=1;i<=n;i++){
            cin>>s[i];
            for(int j=1;j<=m;j++){
                char c = s[i][j-1];
                if(i==1 && j==1) continue;
                if(c == '.'){
                    dp[i][j][0] = (dp[i][j-1][1] + dp[i-1][j][2])%mod;
                    dp[i][j][1] = (dp[i][j-1][1] + dp[i][j][0])%mod;
                    dp[i][j][2] = (dp[i-1][j][2] + dp[i][j][0])%mod;
                }else {
                    dp[i][j][0]=0;
                    dp[i][j][1]=0;
                    dp[i][j][2]=0;
                }
            }
        }
        
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout << dp[i][j][0] << ' ';
            } cout << '\n';
        }*/

        cout << dp[n][m][0]%mod << '\n';
    }

    return 0;
}
/*
1
3 3
...
.*.
...

1
4 4
....
.*..
.**.
....

1
2 4
....
.*..
*/
