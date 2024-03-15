#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T=5;
    while(T--){
        int n; cin>>n;
        vector<pair<int,int>> g[2];
        for(int i=0;i<n-1;i++){
            int u,v; cin>>u>>v;
            g[0].push_back({min(u,v),max(u,v)});
        }
        
        for(int i=0;i<n-1;i++){
            int u,v; cin>>u>>v;
            g[1].push_back({min(u,v),max(u,v)});
        }
        sort(g[0].begin(),g[0].end());
        sort(g[1].begin(),g[1].end());
        bool ch=0;
        for(int i=0;i<n-1;i++){
            if(g[0][i] != g[1][i]){
                ch=1;
                break;
            }
        }
        if(ch) cout << 'N';
        else cout << 'Y';
    }

    return 0;
}