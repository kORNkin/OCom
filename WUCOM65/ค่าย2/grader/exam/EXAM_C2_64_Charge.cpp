#include<bits/stdc++.h>
using namespace std;

int finds(int i ,int par[]){
    if(par[i]==i) return i;
    return par[i] = par[i]/abs(par[i])*finds(abs(par[i]),par);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q; cin>>n>>q;
    int par[n+1];
    int rankk[n+1];
    for(int i=0;i<=n;i++)   
        par[i]=i, rankk[i]=0;
    while(q--){
        char op; int a,b;
        cin>>op>>a>>b;
        int x = finds(a,par);
        int y = finds(b,par);
        a = abs(x), b = abs(y);
        if(op=='A'){
            if(a == b) continue;
            if(rankk[a] < rankk[b]) par[a] = -y;
            else {
                par[b] = -x;
                if(rankk[a] == rankk[b]) rankk[a]++;
            }
        }   
        else if(op=='R'){
            if(a == b) continue;
            if(rankk[a] < rankk[b]) par[a] = y;
            else {
                par[b] = x;
                if(rankk[a] == rankk[b]) rankk[a]++;
            }

        }else {
            if(a==b){
                if(x == y)
                    cout << "R\n";
                else
                    cout << "A\n";
            }else cout << "?\n";
        }
    }
    return 0;
}