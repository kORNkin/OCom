#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000001];

int mn=1e9;
int src,tar;
void bfs(bool vis[]){
    int co=0;

    queue<int> q;
    q.push(src);
    vis[src]=1;

    bool ch=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        co++;

        cout << x << " ";
        if(x==tar)
            break;
        //sort(g[x].begin(),g[x].end());
        for(auto e:g[x]){         
            if(!vis[e]){
                vis[e]=1;
                q.push(e);
            }
        }
    }
    cout << '\n';
    mn = co;
    cout << "bfs:" << mn << '\n';
}
void dfs(bool vis[]){
    int co=0;

    stack<int> st;
    st.push(src);
    vis[src]=1;

    bool ch=0;
    while(!st.empty()){
        int x=st.top();
        st.pop();

        co++;
        cout << x << " ";
        if(x==tar){
            break;
        }
        for(int i=g[x].size()-1;i>=0;i--){
            if(!vis[g[x][i]]){
                vis[g[x][i]]=1;
                st.push(g[x][i]);
            }
        }
    }
    cout << '\n';
    cout << "dfs:" << co << '\n';

    if(mn < co) cout << "BREADTH";
    else if(mn > co) cout << "DEPTH";
    else cout << "EQUAL"; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int V,E; cin>>V>>E>>src>>tar;

    while(E--){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool vis[1000001];
    memset(vis,0,sizeof(vis));
    bfs(vis);
    memset(vis,0,sizeof(vis));
    dfs(vis);

    return 0;
}