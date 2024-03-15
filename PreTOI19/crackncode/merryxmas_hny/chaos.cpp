#include<bits/stdc++.h>
using namespace std;
#define N 100100
struct Node{
    int node;
    bool work;
};
bool vis[N];
vector<Node> g[N];
vector<pair<int,int>> e;
 
void CutEdge(int x){
    for(auto &n:g[e[x].first]){
        if(n.node == e[x].second && n.work){
            n = {n.node,0};
            break;
        }
    }
    for(auto &n:g[e[x].second]){
        if(n.node == e[x].first && n.work){
            n = {n.node,0};
            break;
        }
    }
}
 
void dfs(int i)
{
    vis[i] = 1;
    for(auto n:g[i]){
        if(!vis[n.node] && n.work){
            dfs(n.node);
        }
    }
 
} 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int n,m; cin>>n>>m;
    e.push_back({0,0});
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        g[a].push_back({b,1});
        g[b].push_back({a,1});
        e.push_back({a,b});
    }
    for(int i=0;i<m;i++){
        memset(vis,0,sizeof(vis));
        int x, co=0; cin>>x;
        CutEdge(x);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i);
                co++;
            }
        }
        cout << co << '\n';
    }
 
 
    return 0;
}
/*
6 5
1 2
1 3
2 4
2 5
3 6
1 1

*/