#include<bits/stdc++.h>
using namespace std;
int n,m; 
int par[100001];
int rankk[100001];

int finds(int i){
    if(par[i]==i) return i;
    return par[i] = finds(par[i]); 
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<=n;i++){
        par[i] = i;
    }
    while(m--){
        int a,b; cin>>a>>b;

        a = finds(a);
        b = finds(b);

        if(rankk[a] < rankk[b]) par[a] = b;
        else {
            par[b] = a;
            if(rankk[a] == rankk[b]) rankk[a]++;
        }
    }
    int t; cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        
        a = finds(a);
        b = finds(b);

        if(par[a] == par[b]) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}