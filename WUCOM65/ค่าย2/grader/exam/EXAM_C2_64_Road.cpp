#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct E{
    int u,v,w;
    bool operator < (E &r){ return w<r.w; }
};
long long n,m,sum; 
vector<E> eds;
int par[200001], rnk[200001];
int f(int i) { return (par[i]==i? i: f(par[i])); }
void MST(){
    for(int i=1;i<=n;i++) par[i]=i;
    sort(eds.begin(),eds.end());
    for(auto e:eds){
        int a=f(e.u), b=f(e.v);
        if(a != b){
            if(rnk[a] < rnk[b]) par[a] = b;
            else {
                par[b] = a;
                if(rnk[a] == rnk[b]) rnk[a]++;
            } sum+=e.w;
        }
    }
    cout << sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        eds.push_back({u,v,w});
    } cin>>m;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        eds.push_back({u,v,0});
        sum+=w;
    }
    MST();

    return 0;
}