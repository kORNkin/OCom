#include<bits/stdc++.h>
using namespace std;
int n;
int par[100001];
int rankk[100001];

int finds(int i){
    if(par[i]==i) return i;
    return par[i] = finds(par[i]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<=n;i++)
        par[i] = i;

    int q; cin>>q;
    while(q--){
        char c; int a,b;
        cin>>c>>a>>b;

        a = finds(a);
        b = finds(b);
        if(c == 'c'){
            if(rankk[a] < rankk[b]) par[a] = b;
            else {  
                par[b] = a;
                if(rankk[b] == rankk[a]) rankk[a]++;
            }       
        }else{
            if(par[a] == par[b]) cout << "yes\n";
            else cout << "no\n";
        }
    }

    return 0;
}