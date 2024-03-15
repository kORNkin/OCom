#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define f first
#define s second
struct E{
    long long dis,n;
    bool operator < (E &a){
        return dis > a.dis;
    }
};
int k,q;
set<pair<int,int>> nodes;
map<pair<int,int>, int> mp;
map<pair<int,int>, pair<int,int>> mem;
vector<E> G[100001];

long long Dis(pair<int,int> a, pair<int,int> b){
    return abs(a.first - b.first)+abs(a.second - b.second);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>k>>q;
    int cnt=0;
    while(k--){
        int a,b,x,y; cin>>a>>b>>x>>y;
        nodes.insert({a,b});
        nodes.insert({x,y});
        mem[{a,b}] = {x,y};
        mem[{x,y}] = {a,b};
        if(!mp.count({a,b})){
            mp[{a,b}] = cnt;
            cnt++;
        }
        if(!mp.count({x,y})){
            mp[{x,y}] = cnt;
            cnt++;
        }
        G[mp[{a,b}]].push_back({0,mp[{x,y}]});
        G[mp[{x,y}]].push_back({0,mp[{a,b}]});
    }   

    for(auto node1:nodes){
        for(auto node2:nodes){
            if(node1 != node2 && mem[node1]!=node2){
                G[mp[node1]].push_back({Dis(node1,node2), mp[node2]});
            }
        }
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    while(q--){ 
        int a,b,x,y;
        cin>>a>>b>>x>>y;    
        vector<E> g[100001];
        for(auto node:nodes){
            for(auto x:G[mp[node]]){
                g[mp[node]].push_back({x.dis,x.n});
            }
            g[mp[node]].push_back({Dis(node,{a,b}), cnt});
            g[cnt].push_back({Dis(node,{a,b}), mp[node]});

            g[mp[node]].push_back({Dis(node,{x,y}), cnt+1});
            g[cnt+1].push_back({Dis(node,{x,y}), mp[node]});
        }

        g[cnt].push_back({Dis({x,y},{a,b}), cnt+1});
        g[cnt+1].push_back({Dis({x,y},{a,b}), cnt});

        vector<int> dis(cnt+5,1e9);
        vector<bool> vis(cnt+5,0);
        pq.push({0,cnt});
        dis[cnt] = 0;
        while(!pq.empty()){
            int idx = pq.top().second;
            pq.pop();

            if(vis[idx]) continue;
            vis[idx] = 1;

            for(auto e:g[idx]){
                if(dis[e.n] > e.dis + dis[idx]){
                    dis[e.n] = e.dis + dis[idx];
                    pq.push({dis[e.n],e.n});
                }
            }
        }
        cout << dis[cnt+1] << '\n';
    }
    
    return 0;
}
/*
2 1
10 0 100 10
0 10 0 1000
0 0 200 10
*/