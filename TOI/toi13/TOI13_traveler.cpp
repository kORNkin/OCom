/*TASK:
LANG: C++
AUTHOR: Supphakon Yimi
CENTER: WU
*/
#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
#define mod 1000000007
#define st first
#define nd second
#define pr pair<int,int>
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

int n,m,src,k,d;

bool cmp(pr a, pr b)
{
    if(a.nd == b.nd) return a.st < b.st;
    return a.nd < b.nd;
}

vector<pr> dijkstra(int src,vector<pr> g[], bool vis[])
{
    vector<int> dist(n);
    for(int i=0;i<n;i++)
        dist[i]=1e9;
    dist[src]=0;
    priority_queue<pr,vector<pr>,greater<pr>> pq;
    pq.push({src,0});
    while(!pq.empty())
    {
        pr tmp = pq.top();
        int s = tmp.st, w = tmp.nd;
        pq.pop();

        if(vis[s])
            continue;
        vis[s] = 1;

        for(auto e:g[s])
        {
            int node = e.st;
            int wg = e.nd;

            if(dist[node] > dist[s]+wg)
            {
                dist[node] = dist[s]+wg;
                pq.push({node,dist[node]});
            }
        }
    }
    
    vector<pr> tmp(n);
    for(int i=0;i<n;i++)
    {
        tmp[i].st = i;
        tmp[i].nd = dist[i];
    } return tmp;
    for(int i=0;i<n;i++)
        cout << src << " to node:" << i << " dist: " << dist[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> src >> k >> d;

    vector<pr> g[m+5];
    bool vis[m+5];
    vector<pr> dis1(n+5),dis2(n+5);

    while(m--)
    {
        int u,v,w;
        cin >> u >>v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    memset(vis,0,sizeof(vis));
    dis1 = dijkstra(src,g,vis);
    if(dis1[k].nd <= d)
    {
        cout << k << " " << dis1[k].nd << " " << 0;
        return 0;
    }

    memset(vis,0,sizeof(vis));
    dis2 = dijkstra(k,g,vis);

    int nearest_dist =1e9,ans_node,ans_budget;
    for(int i=0;i<n;i++)
    {
        if(dis2[i].nd < nearest_dist && dis1[i].nd <= d)
        {
            ans_node = i;
            ans_budget = dis1[i].nd;
            nearest_dist = dis2[i].nd;
        }
    }
    cout << ans_node << " " << ans_budget << " " << nearest_dist;




    return 0;

}
/*
8 11
0 5 200
0 1 10
0 2 10
1 3 10
1 5 70
2 3 10
2 4 30
2 6 10
3 5 30
4 5 20
6 7 15
7 5 20

5 50 0
*/