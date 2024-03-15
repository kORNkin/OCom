#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct E{
    int u,v,w;
    bool operator < (const E &r){ return w > r.w; }
};
vector<E> edges;
int n, m, s, d, k, par[2501], rnk[2501];
int finds(int i){ return (par[i]==i? i: par[i]=finds(par[i])); }
void MST(){
    for(int i = 1; i <= n; i++) par[i]=i;
    sort(edges.begin(),edges.end());
    int cnt = m;
    for(E e:edges){
        if(cnt == m-n) break;
        int a = finds(e.u), b = finds(e.v);
        if(a != b){
            cnt--;
            if(rnk[a] < rnk[b]) par[a] = b;
            else {
                par[b] = a; if(rnk[a] == rnk[b]) rnk[a]++;
            } 
            if(finds(s)==finds(d)){
                cout << ceil((double)k/(double)(e.w-1));
                return ;
            }
        }
    } 
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v,w; cin>>u>>v>>w;
        edges.emplace_back(E{u,v,w});
    } cin >> s >> d >> k;
    MST();

    return 0;
}