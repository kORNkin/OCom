#include<bits/stdc++.h>
using namespace std;
long long G[30];
void solve(int n){
    int it = lower_bound(G,G+29, n) - G;
    bool ch=0;
    while(n>3){
        if(n==G[it-1]+1){
            cout << "g "; ch=1; break;
        }else if(n > G[it-1]+1 && n < G[it-1]+it+4){
            cout << "a "; ch=1; break;
        }    
        n -= G[it-1]+it+3;
        it = lower_bound(G,G+29, n) - G;
    }
    if(!ch){
        if(n==1) cout << "g ";
        else cout << "a ";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    G[0] = 3;
    for(int i=1;i<=28;i++){
        G[i] = G[i-1] + 3 + i + G[i-1];
    }

    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        solve(n);
    }
    return 0;
}
