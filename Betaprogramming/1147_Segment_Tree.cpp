#include<bits/stdc++.h>
using namespace std;
const int N = 262145;
int t[2 * N],n,q;
void update(int i,int v){
    for(t[i+=n]=v ; i>1; i>>=1) t[i>>1] = max(t[i],t[i^1]);
}
int query(int l,int r){
    int ans=-1e9;
    for(l+=n, r+=n; l <= r; l>>=1, r>>=1){
        if(l&1) ans=max(ans,t[l++]);
        if(!(r&1)) ans=max(ans,t[r--]);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    while(q--){
        char c; int a,b;
        cin>>c>>a>>b;
        if(c^'P') update(a,b);
        else cout << query(a,b) << '\n';
    }
    return 0;
}