#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t[2 * N],n,k;

void update(int i,int v){
    for(t[i+=n]=v; i>1; i>>=1) t[i>>1] = max(t[i], t[i^1]);
}
int query(int l,int r){
    int ans = 0;
    for(l+=n, r+=n; l<=r; l>>=1, r>>=1){
        if(l&1) ans = max(ans, t[l++]);
        if(!(r&1)) ans = max(ans, t[r--]);
    } 
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>k;
    while(k--){
        int x,h; cin>>x>>h;
        update(x,h);

        int l=0, r=n;
        while(l < r){
            int m = (l+r+1)>>1;
            if(query(max(0, x-m), min(n-1, x+m)) > h)
                r = m-1;
            else l = m;
        }
        cout << l << '\n';
    }

    return 0;
}