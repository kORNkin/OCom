#include<bits/stdc++.h>
using namespace std;
int dp[201][201];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string a; cin>>a;

    int T; cin>>T;
    while(T--){
        string b; cin>>b;
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=a.size();i++){
            for(int j=1; j<=b.size();j++){
                if(a[i-1] == b[j-1]) 
                    dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << dp[a.size()][b.size()] << '\n';
    }

    return 0;
}