#include<bits/stdc++.h>
using namespace std;

int n, k, t, cnt, ans;
vector<int> g[100001], lv[100001];
int vis[100001];

bool dfs(int ind){
    if(vis[ind] == 1) return 0;
    if(vis[ind] == 2) return 1;

    cnt++;
    vis[ind] = 2;

    for(auto v:g[ind]){
        if(dfs(v)) return 1;
    }
    vis[ind] = 1;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> t;
    for(int i = 1; i <= n; i++){
        int l, p; cin >> l >> p;
        lv[l].push_back(i);
        while(p--){
            int v; cin >> v;
            g[i].push_back(v);
        }
    }

    int ans = -1;
    for(int i = 1; i <= k; i++){
        bool loop = 0;
        for(auto v:lv[i]){
            if(dfs(v)){
                loop = 1; break;
            }
        }
        if(loop || cnt > t) break;

        ans = i;
    }

    cout << ans;

    return 0;
}