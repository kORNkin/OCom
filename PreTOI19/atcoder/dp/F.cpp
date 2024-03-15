#include<bits/stdc++.h>
using namespace std;

string a, b;
int dp[3001][3001];
int lcs(int i, int j){
    if(i <= 0 || j <= 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(a[i - 1] == b[j - 1]) dp[i][j] = lcs(i - 1, j - 1) + 1;
    else dp[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));

    return dp[i][j];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    memset(dp, 0, sizeof(dp));
    //lcs(a.size(), b.size());

    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            int x = max(dp[i][j - 1], dp[i - 1][j]);
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = x;
        }
    }

    int i = a.size(), j = b.size(); 
    stack<char> st;
    while(i >= 1 && j >= 1){
        if(a[i - 1] == b[j - 1]){
            st.push(a[i - 1]);
            i--, j--;
        }else {
            if(dp[i - 1][j] >= dp[i][j - 1]) i--;
            else j--;
        }
    }

    while(!st.empty()) cout << st.top(), st.pop();

    return 0;
}
