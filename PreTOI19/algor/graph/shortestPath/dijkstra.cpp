#include<bits/stdc++.h>
using namespace std;
#define edge second 
#define wg first
#define N 7
typedef pair<int,int> pii;
vector<pii> g[N];
void addE(int x,int y,int z){
    g[x].push_back({z,y});
    g[y].push_back({z,x});
}

void dijkstra(int src,int tg){
    int dis[N];
    bool vis[N];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<N;i++)
        dis[i] = 1e9;
    dis[src]=0;
    priority_queue<pii , vector<pii> , greater<pii>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        pii tmp = pq.top();
        pq.pop();
        if(vis[tmp.edge]) continue;
        for(auto e:g[tmp.edge]){
            if(dis[tmp.edge]+e.wg < dis[e.edge]){
                dis[e.edge]=dis[tmp.edge]+e.wg;
                vis[tmp.edge]=1;
                pq.push({dis[e.edge],e.edge});
            }
        }
    }
    for(int i=0;i<7;i++)
        cout << dis[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    addE(0,1,3);
    addE(0,2,2);
    addE(1,2,2);
    addE(1,4,4);
    addE(1,3,1);
    addE(2,3,3);
    addE(2,5,5);
    addE(2,6,6);
    addE(3,6,2);
    addE(4,6,1);
    addE(5,6,2);

    dijkstra(0,6);
        

    return 0;
}