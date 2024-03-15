#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, q, low[100001], tin[100001], cnt, arr[100001];
vector<ll> g[100001]; 
bitset<100001> vis, inst;
stack<ll> st;
vector<ll> scc;

void dfs(int u){
    low[u] = tin[u] = ++cnt;
    vis[u] = inst[u] = 1;
    st.push(u);
    for(auto &v : g[u]){
        if(!vis[v]) 
            dfs(v);
        if(inst[v])
            low[u] = min(low[v], low[u]);
    }

    if(low[u] == tin[u]){
        ll dis = 0;
        while(st.top() != u){
            inst[st.top()] = 0; 
            dis += arr[st.top()];
            st.pop();
        }
        inst[st.top()] = 0;
        dis += arr[st.top()];
        st.pop();
        scc.push_back(dis);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    while(m--){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }   

    dfs(1);

    sort(scc.begin(), scc.end());
    while(q--){
        ll x ; cin >> x;
        cout << upper_bound(scc.begin(), scc.end(), x) - scc.begin()<< '\n';
    }   

    return 0;
}
