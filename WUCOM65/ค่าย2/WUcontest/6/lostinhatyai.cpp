#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define f first
#define s second
int n,m,q;
char g[1001][1001];
bool vis[1001][1001];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
map<pair<int,int>, pair<int,int>> mp;

pair<int,int> f(pair<int,int> i){
    if(mp[i]==i) return i;
    return mp[i] = f(mp[i]);
}

bool valid(int x,int y){
    if(x<1 || y<1 || x>n || y>m || g[x][y] == '#'){
        return 0;
    } return !vis[x][y];
}

void flood(int x,int y){
    vis[x][y] = 1;

    for(int i=0;i<4;i++){
        int xx=x+dx[i], yy=y+dy[i];
        if(valid(xx,yy)){
            mp[{xx,yy}] = {x,y};
            flood(xx,yy);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>q;
    vector<pair<int,int>> mem;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            if(g[i][j]=='.') mem.push_back({i,j});
            mp[{i,j}] = {i,j};
        }
    }
    for(auto e:mem){
        if(!vis[e.first][e.second]){
            flood(e.first,e.second);
        }
    }
    
    while(q--){
        int a,b,x,y; cin>>a>>b>>x>>y;
        if(f({a,b}) == f({x,y})){
            cout << "YES\n";
        }else cout<< "NO\n";
    }

    return 0;
}