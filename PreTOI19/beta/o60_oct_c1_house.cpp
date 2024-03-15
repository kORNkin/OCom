#include<bits/stdc++.h>
using namespace std;
const int N = 200001;
struct node{ 
    int sum, l, r, ans; 
    node(){}
    node(int val){
        sum = val;
        l = val;
        r = val;
        ans = val;
    }
} t[N << 1];
int n,m,x;
node cal(node a, node b){
    node res;
    res.sum = a.sum + b.sum;
    res.l = max(a.l, a.sum + b.l);
    res.r = max(b.r, b.sum + a.r);
    res.ans = max(a.ans, max(b.ans, a.r + b.l));
    return res;
}

void build(){
    for(int i = n; --i;) t[i] = cal(t[i<<1], t[i<<1|1]);
}
int query(int l,int r){
    node resl = node(0), resr = node(0);
    for(l+=n, r+=n; l<=r; l>>=1, r>>=1){
        if(l&1) resl = cal(resl, t[l++]);
        if(!(r&1)) resr = cal(t[r--], resr);
    }
    return cal(resl,resr).ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>x, t[i + n] = node(x);
    build();
    while(m--){
        int a,b; cin>>a>>b;
        cout << query(a,b) << '\n';
    }

    return 0;
}