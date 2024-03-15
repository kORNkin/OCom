#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define f first
#define s second
int n,q;
int par[200001];
vector<int> sz(200001, 1);

int f(int i){
    if(par[i] == i) return i;
    return par[i] = f(par[i]);
}

void merge(int a,int b){
    if(sz[a] < sz[b]){
        par[a] = b;
        sz[b] += sz[a];
    }else {
        par[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>q;
    for(int i=0;i<n;i++) par[i]=i;
    while(q--){
        int a,b; cin>>a>>b;
        a = f(a);
        b = f(b);
        if(a!=b) merge(a,b);
    }
    vector<int> ans;
    int cnt=0;
    bool vis[n+1]; memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(!vis[f(i)]){
            vis[f(i)]=1;
            cnt++;
            ans.push_back(sz[f(i)]);
        }
    }
    cout << cnt << '\n';
    sort(ans.begin(),ans.end(), greater<int>());
    for(auto e:ans) cout << e << ' ';

    return 0;
}