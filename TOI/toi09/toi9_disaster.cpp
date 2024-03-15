#include<bits/stdc++.h>
using namespace std;

int n, cnt[26], vis[26][26];
char u, v;
vector<char> g[26];
set<char> s;

void dfs(char c){
    cout << c << ' ';
    int a = c - 'A', b;
    for(auto v:g[c - 'A']){
        b = v - 'A';
        if(!vis[a][b]){
            vis[a][b] = vis[b][a] = 1;
            dfs(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
   
    cin >> n;
    while(n--){
        cin >> u >> v;
        g[u - 'A'].push_back(v); cnt[u - 'A']++;
        g[v - 'A'].push_back(u); cnt[v - 'A']++;
        s.insert(u);
        s.insert(v);
    }
    for(auto c:s) {
        if(cnt[c]&1){
            dfs(c); return 0;
        }
    } dfs(v);

    return 0;
}