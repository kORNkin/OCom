#include <bits/stdc++.h>
using namespace std;

int n, arr[256], dp[256][256][3], segi[] = {2,1,0,2,1,1,1,2,1};
vector<pair<int, int>> tiga[3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tiga[segi[i * 3 + j]].push_back({i,j});
        }
    }

    int t = 20;
    while(t--){
        memset(dp, 0,sizeof(dp));
        cin >> n; 
        char s;
        for(int i = 0; i < n; i++) cin >> s, dp[i][i][s-'0'] = 1;

        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                for(int c = 0; c < 3; c++){
                    for(int k = i; k < j; k++){
                        for(auto &t : tiga[c]){
                            if(dp[i][k][t.first] && dp[k+1][j][t.second]){
                                dp[i][j][c] = 1;
                                break;
                            }
                        }
                        if(dp[i][j][c]) break;
                    }
                }
            }
        }
        if(dp[0][n - 1][0]) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;

}