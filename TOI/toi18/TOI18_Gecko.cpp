/*
Author: kornkin.png
Algor: Topological Sort 
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pii;
int n, m, k, p;
int gacko[20001];
vector<pii> g[20001];
vector<int> topo[20001];
vector<pair<pii,pii>> ans;

set<pii> chk;
unordered_set<int> all;
int indegree[20001];

void Topo(){
    queue<int> q;
    for(auto i:all) if(!indegree[i]) q.push(i); 
    
    
    while(!q.empty()){
        int idx = q.front();
        q.pop();

        for(auto e:topo[idx]){
            --indegree[e];

            int a = min(e,idx), b = max(e,idx);
            if(chk.find({a,b}) != chk.end()) 
                cout << a << ' ' << b << '\n';
            chk.erase({a,b});
            
            if(!indegree[e]) q.push(e);
        }
    }
}

void D(){
    long long dis[n];
    int vis[n], par[n];
    for(int i = 0; i < n; i++) dis[i] = 1e18, par[i] = i;
    memset(vis,0,sizeof(vis));

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,p});
    dis[p] = 0;
    while(!pq.empty()){
        int idx = pq.top().second;
        pq.pop();

        if(vis[idx]) continue;
        vis[idx] = 1;
        for(auto &e:g[idx]){
            if(dis[idx] + e.second <= dis[e.first]){
                dis[e.first] = dis[idx] + e.second;
                par[e.first] = idx;
                pq.push({dis[e.first], e.first}); 
            }
        }
    }   

    for(int i = 0; i < k; i++) {
        cout << dis[gacko[i]] << ' ';
        for(int j = gacko[i]; j != p; j = par[j]){
            int a = j, b = par[j];
            if(chk.find({min(a,b),max(a,b)}) != chk.end()) continue;
            chk.insert({min(a,b),max(a,b)});
            topo[a].push_back(b);
            all.insert(a);
            all.insert(b);
            ++indegree[b]; 
        } 
    } cout << '\n' << chk.size() << '\n';

    Topo();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k >> p;
    for(int i = 0; i < k; i++) cin >> gacko[i];
    for(int i = 0; i < m; i++){
        long long u,v,w; cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    D();

    return 0;
}