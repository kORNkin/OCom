#include<bits/stdc++.h>
using namespace std;
// 0 = n, 1 = s, 2 = e, 3 = w;
int m, n, cnt;
int g[301][301];
int di[] = {-1,1,0,0};
int dj[] = {0,0,1,-1};
vector<int> dis;

void flood(int i, int j, int cur){
    cnt++;
         if(g[i][j] == 11) cur = (cur==1? 3: 0);
    else if(g[i][j] == 12) cur = (cur==1? 2: 0);
    else if(g[i][j] == 13) cur = (cur==0? 3: 1);
    else if(g[i][j] == 14) cur = (cur==0? 2: 1);
    if(g[i][j] == 31) g[i][j] = (cur==1 || cur==0? 22: 21);
    else g[i][j] = 0;
    int ii = i + di[cur], jj = j + dj[cur];
    if(ii < 0 || jj < 0 || ii >= m || jj >= n) return;
    flood(i+di[cur], j+dj[cur], cur);
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
        } 
    }
    for(int i = 0; i < n; i++) {
        cnt = 0;
        if(g[0][i] == 11 || g[0][i] == 12 || g[0][i] == 21 || g[0][i] == 31)
            flood(0,i,1), dis.push_back(cnt);
    }
    for(int i = 0; i < n; i++) {
        cnt = 0;
        if(g[m-1][i] == 13 || g[m-1][i] == 14 || g[m-1][i] == 21 || g[m-1][i] == 31) 
            flood(m-1,i,0), dis.push_back(cnt);
    }
    for(int i = 0; i < m; i++){
        cnt = 0;
        if(g[i][0] == 11 || g[i][0] == 13 || g[i][0] == 22 || g[i][0] == 31) 
            flood(i,0,2), dis.push_back(cnt);
    }
    for(int i = 0; i < m; i++){
        cnt = 0;
        if(g[i][n-1] == 12 || g[i][n-1] == 14 || g[i][n-1] == 22 || g[i][n-1] == 31) 
            flood(i,n-1,3), dis.push_back(cnt);
    }
    
    cout << dis.size() << '\n';
    for(auto &d:dis) cout << d << ' ';

    return 0;
}