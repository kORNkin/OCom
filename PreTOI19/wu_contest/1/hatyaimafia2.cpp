#include<bits/stdc++.h>
using namespace std;
int n, m, q, par[200001], sz[200001], l[200001], mid[200001], r[200001];
pair<int, int> op[300001], qt[200001];
vector<int> in_mid[300001];

int findP(int i, int p) { return (i == p ? i : par[i] = findP(p, par[p])); }

void uni(int a, int b){
    a = findP(a, par[a]);
    b = findP(b, par[b]);
    if(a == b) return;

    if(sz[a] < sz[b]) par[a] = b;
    else {
        par[b] = a;
        if(sz[a] == sz[b]) sz[a]++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        op[i] = {u, v};
    }

    for(int i = 1; i <= q; i++){
        int u, v; cin >> u >> v;
        qt[i] = {u, v};
    }

    for(int i = 1; i <= q; i++) {
        l[i] = 1, r[i] = m;
    }

    while(1){
        int cnt = 0;

        for(int i = 1; i <= q; i++){
            if(l[i] == r[i]) cnt++;
            else {
                mid[i] = (l[i] + r[i]) >> 1;
                in_mid[mid[i]].push_back(i);
            }
        }

        if(cnt == q) break;

        for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 0;

        for(int i = 1; i <= m; i++){
            uni(op[i].first, op[i].second);

            for(int idx : in_mid[i]){
                if(l[idx] == r[idx]) continue;
                if(findP(qt[idx].first, par[qt[idx].first]) == findP(qt[idx].second, par[qt[idx].second]))
                    r[idx] = mid[idx];
                else l[idx] = mid[idx] + 1; 
            }

            in_mid[i].clear();
        }
    }

    for(int i = 1; i <= q; i++){
        if(l[i] == m && findP(qt[i].first, par[qt[i].first]) != findP(qt[i].second, par[qt[i].second]))
            cout << "-1\n";
        else cout << l[i] << '\n';
    }

    return 0;
}
