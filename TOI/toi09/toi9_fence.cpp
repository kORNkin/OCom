#include<bits/stdc++.h>
using namespace std;

int qs[501][501];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int T = 2;
    while(T--){
        int m, n, t; cin >> m >> n >> t;
        memset(qs, 0, sizeof(qs));
        while(t--){
            int x, y; cin >> x >> y;
            qs[x + 1][y + 1] = 1;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
            }
        }
        bool ch = 1;
        for(int k = min(m,n); k >= 1 && ch; k--){
            for(int i = k; i <= m && ch; i++){
                for(int j = k; j <= n && ch; j++){
                    int a = qs[i][j] - qs[i-k][j] - qs[i][j-k] + qs[i-k][j-k];
                    int b = qs[i-1][j-1] - qs[i-1][j-k+1] - qs[i-k+1][j-1] + qs[i-k+1][j-k+1];
                    if(!(a - b)){
                        cout << k << '\n'; ch = 0;
                        break;
                    }
                }
            }
        }
    }
    
    return 0;
}

