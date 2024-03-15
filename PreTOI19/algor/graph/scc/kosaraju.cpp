#include<bits/stdc++.h>
using namespace std;
vector<int> g[1001], rg[1001];
bitset<1001> vis;
vector<int> st, scc;

void dfs(int i, int pass = 0){
    vis[i] = 1;

    for(auto &v: (pass? rg[i]: g[i])){
        if(!vis[v]){
            dfs(v, pass);
        }
    }
    
    if(pass){
        scc.push_back(i);
    }else st.push_back(i);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    vis.reset();
    int cntScc = 0;
    for(int i = n-1; i>=0; i--){
        if(!vis[st[i]]){
            cntScc++;
            scc.clear();
            dfs(st[i],1);
            for(auto e:scc){
                cout << e << ' ';
            }
            cout << '\n';
        }
    }
    cout << "scc: " << cntScc;

    return 0;
}
/*
5 50
1 0
0 2
2 1
0 3
3 4
*/