#include<bits/stdc++.h>
using namespace std;
vector<int> g[1001];
bitset<1001> vis, onst;
stack<int> st;
int low[1001], id[1001], cnt, cntScc;

void dfs(int i){
    low[i] = id[i] = ++cnt;
    onst[i] = vis[i] = 1;
    st.push(i);
    for(auto &v:g[i]){
        if(!vis[v]){
            dfs(v);
        }
        if(onst[v]){
            low[i] = min(low[i], low[v]);
        }
    }

    if(low[i] == id[i]){
        ++cntScc;
        while(st.top() != i){
            cout << st.top() << ' ';
            onst[st.top()] = 0;
            st.pop();
        }
        cout << st.top() << ' ';
        onst[st.top()] = 0;
        st.pop();
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
    }

    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    cout << cntScc;

    return 0;
}
/*
5 5
1 0
0 2
2 1
0 3
3 4
*/