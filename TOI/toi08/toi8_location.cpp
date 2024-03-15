#include<bits/stdc++.h>
using namespace std;
int m, n, k, qs[1001][1001], mx;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    cin >> m >> n >> k; 
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> qs[i][j];
            qs[i][j] += qs[i][j - 1] + qs[i - 1][j] - qs[i - 1][j - 1]; 
            if(min(i,j) >= k) 
                mx = max(mx, qs[i][j] - qs[i - k][j] - qs[i][j - k] + qs[i - k][j - k]);
        }
    }
    cout << mx;

    return 0;
}