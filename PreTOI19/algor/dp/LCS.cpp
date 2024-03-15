#include<bits/stdc++.h>
using namespace std;
string sa = "ILOVESOMUCHEIEI", sb = "IMGONNAPECKMYTHING";
int dp[1001][1001];
string ans;
int solve(string a,string b){
    if(a == "" || b == "") return 0;
    int x = a.size(), y = b.size();
    if(dp[x][y]) return dp[x][y];
    
    if(a.back() == b.back()){
        ans.push_back(a.back());
        a.pop_back(), b.pop_back();
        dp[x][y] = 1 + solve(a,b);
    }else {
        a.pop_back(); 
        dp[x][y] = solve(a,b);
        b.pop_back();
        dp[x][y] = max(dp[x][y],solve(a,b));

    }   return dp[x][y];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    
    cout << solve(sa,sb) << '\n';
    reverse(ans.begin(),ans.end());
    cout << ans << '\n';

    string ans = "";
    int n = sa.size(),m = sb.size();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){  
            if(sa[i-1] == sb[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans.push_back(sa[i-1]);
            }else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    } cout << dp[n][m] << '\n';
    reverse(ans.begin(),ans.end());
    cout << ans << '\n';

    return 0;
}