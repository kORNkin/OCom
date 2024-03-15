#include<bits/stdc++.h>
using namespace std;

long long n, m, dp[51][51];
bitset<51> dad[51];

long long solve(int x, int y){
    if(dad[x][y]) return 0;
    if(x == n && y == m) return 1;

    if(dp[x][y]) return dp[x][y];
    if(x < n) dp[x][y] += solve(x + 1, y);
    if(y < m) dp[x][y] += solve(x, y + 1);
    return dp[x][y];
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    int t; cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        dad[x][y] = 1;
    }

    cout << solve(1,1);

    return 0;
}
