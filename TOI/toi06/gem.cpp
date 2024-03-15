#include<bits/stdc++.h>
using namespace std;

//--- optional (faster ~300ms) ---
void scan(int &n){
    char c; n = 0;
    c = getchar();
    if(c <= 47 || c >= 58) c = getchar();
    for(; c > 47 && c < 58; c = getchar())
        n = n * 10 + c - 48;
}
//--------------------------------

int n, m, low[200001], tin[200001], onst[200001], cnt;
stack<int> st;
bitset<200001> vis;

void dfs(int u, vector<int> g[]){
    low[u] = tin[u] = ++cnt;
    onst[u] = vis[u] = 1;
    st.push(u);
    for(auto &v:g[u]){
        if(!vis[v]) dfs(v, g);
        if(onst[v]) low[u] = min(low[u], low[v]);
    }
    if(low[u] == tin[u]){
        while(st.top() != u) onst[st.top()] = 0, st.pop();
        onst[st.top()] = 0, st.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 5;
    while(t--){
        //cin >> n >> m;
        scan(n), scan(m);
        vector<int> g[m + 1];
        pair<int ,int> gem[n];
        int no[m + 1];
        for(int i = 0; i < n; i++){
            //cin >> gem[i].first >> gem[i].second;
            scan(gem[i].first), scan(gem[i].second);
        }
        for(int i = 0; i < m>>1; i++){
            int a, b; 
            //cin >> a >> b;
            scan(a), scan(b);
            no[a] = b;
            no[b] = a;
        }
        for(int i = 0; i < n; i++){
            g[no[gem[i].first]].push_back(gem[i].second);
            g[no[gem[i].second]].push_back(gem[i].first);
        }

        vis.reset();
        cnt = 0;

        for(int i = 1; i <= m; i++){
            if(!vis[i])
                dfs(i, g);
        }
        bool ch = 0;
        for(int i = 1; i <= m; i++){
            if(low[i] == low[no[i]]){
                ch = 1; break;
            }
        }
        cout << (ch? "N": "Y");
    }

    return 0;
}