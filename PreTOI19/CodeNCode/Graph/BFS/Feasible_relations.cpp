#include<bits/stdc++.h>
using namespace std;
struct equaler{
    int u,v;
    bool r;
};
int par[1000001];
int findPar(int n){
    if(n != par[n]){
        return par[n] = findPar(par[n]);
    } return par[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while(T--){
        int N,K; cin>>N>>K;
        vector<int> g[N+1];
        vector<equaler> input;
        
        for(int i=1;i<=N;i++)
            par[i]=i;
            
        while(K--){
            string r;
            int u,v; cin>>u>>r>>v;
            if(r=="=") input.push_back({u,v,1});
            else input.push_back({u,v,0});
        }
        sort(input.begin(),input.end(),[&](equaler a, equaler b){
            return a.r>b.r;
        });

        bool ch=0;
        for(auto e:input){
            if(e.r){
                int u = findPar(par[e.u]);
                int v = findPar(par[e.v]);
                par[v] = par[u];
            }else {
                int u = findPar(par[e.u]);
                int v = findPar(par[e.v]);
                if(par[u] == par[v]){
                    ch=1;
                    break;
                }
            } 
        }
        if(ch) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}