#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define st first
#define nd second
typedef long long ll;
int n,m,l,q;
struct room
{
    int now, po_cnt ,last;
    ll w;
    bool operator< (const room &r) const{
        return r.w < w;
    }
};
vector<pii> g[100100];
ll dist[15][100100];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>l>>q;
    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
    }
    vector<bool> po(n+1,0);
    int a;
    while(l--){
        cin>>a;
        po[a]=1;
    }
    for(int i=0;i<=q;i++)
        for(int j=1;j<=n;j++)
            dist[i][j]=1e18;
    dist[0][1]=0;
    priority_queue<room> pq;
    pq.push({1,0,0,0});
    while(!pq.empty()){     
        room tp=pq.top();
        pq.pop();
        if(tp.now==n){
            cout << tp.w;
            return 0;
        }
        if(po[tp.now] && tp.now!=tp.last && tp.po_cnt < q){
            pq.push({tp.now,tp.po_cnt+1,tp.now,tp.w});
        }
        for(auto e : g[tp.now]){
            if(dist[tp.po_cnt][e.st] > tp.w+e.nd/(1<<tp.po_cnt)){
                dist[tp.po_cnt][e.st] = tp.w+e.nd/(1<<tp.po_cnt);
                pq.push({e.st,tp.po_cnt,tp.last,dist[tp.po_cnt][e.st]});
            }
        }
    }
    return 0;
}