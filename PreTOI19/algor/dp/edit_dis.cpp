#include<bits/stdc++.h>
using namespace std;
int dp[501][501];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string word2 = "horse";
    string word1 = "ros";

    for(int i = 0; i <= word1.size(); i++) dp[i][0] = i;
    for(int i = 0; i <= word2.size(); i++) dp[0][i] = i;

    for(int i = 1; i <= word1.size(); i++){
        for(int j = 1; j <= word2.size(); j++){
            if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
        }
    }

    for(int i = 1; i <= word1.size(); i++){
        for(int j = 1; j <= word2.size(); j++){
            cout << dp[i][j] << ' ';
        } cout << '\n';
    }

    return 0;
}