#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops")
using namespace std;
int f(int i,int x,int par[]){
    if(par[i]==i) return i;
    if(par[i]==x) return x;
    return par[i] = f(par[i],x,par);
}
int fds(int i,int par[]){
    if(par[i]==i) return i;
    return fds(par[i],par);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,q; cin>>n>>q;
    int par[n+5];
    for(int i=1;i<=n;i++)    
        cin>>par[i];
    for(int i=1;i<=n;i++)
        f(i,i,par);
    while(q--){
        int s,e,a,b; cin>>s>>e>>a>>b;
        swap(par[a],par[b]);
        if(fds(s,par) != fds(e,par)) cout << "SURVIVE\n";
        else cout << "DEAD\n";
        swap(par[a],par[b]);
    }

    return 0;
}