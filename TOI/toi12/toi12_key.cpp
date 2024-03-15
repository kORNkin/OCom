#include<bits/stdc++.h>
using namespace std;

string a, b, c;
int n;
bitset<2001> dp[2001], vis[2001];

bool check(int i, int j){
    if(vis[i][j]) return dp[i][j]; 

    bool ch = 0;
    if(a[i] == c[i + j]){
        dp[i + 1][j] = check(i + 1, j);
        ch |= dp[i + 1][j];
        vis[i][j] = 1;
    }
    if(b[j] == c[i + j]){
        dp[i][j + 1] = check(i, j + 1);
        ch |= dp[i][j + 1];
        vis[i][j] = 1;
    }

    return dp[i][j] = ch;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> a >> b;
    cin >> n;
    while(n--){
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        cin >> c;

        dp[a.size()][b.size()] = vis[a.size()][b.size()] = 1;
        if(check(0,0)) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
