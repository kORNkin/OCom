#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, d, k, ans;
char c;
vector<pair<int, int>> tree;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d >> k;
    int qs[n + 1][m + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c;
            if(c == 'M') tree.push_back({i, j});
            if(c == 'S') qs[i][j] = qs[i -1][j] + qs[i][j - 1] - qs[i - 1][j - 1] + 1;
            else qs[i][j] = qs[i -1][j] + qs[i][j - 1] - qs[i - 1][j - 1];
        }
    }

    for(auto &[x, y] : tree){
        int a = min(x + d, n);
        int b = min(y + d, m);
        int c = max(x - d - 1, 0);
        int e = max(y - d - 1, 0);
        int dd = qs[a][b] - qs[a][e] - qs[c][b] + qs[c][e];
        if(dd >= k) ans++;
    }

    cout << ans;

    return 0;
}