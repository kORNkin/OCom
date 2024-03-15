#include<bits/stdc++.h>
using namespace std;
bitset<1<<21> t;
int n,k,m,cnt;

void update(int i){
    if(t[i]) return;
    t[i] = 1;
    cnt += (i>=n);
    if(i > 1){
        if(t[i>>1]) update(i^1);
        else if(t[i^1]) update(i>>1);
    }
    if(i < n && (t[i<<1] ^ t[i<<1|1])) update(t[i<<1]? i<<1|1 : i<<1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>k>>m; n = (1<<k);
    for(int i=1; i<=m; i++){
        int a,b; cin>>a>>b;   
        update(b / (1<<a) + (1<<(k-a)));       
        if(cnt>=n) {
            cout << i; return 0;
        }
    }

    return 0; 
}