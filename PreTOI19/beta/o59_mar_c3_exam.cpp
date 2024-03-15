#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
using namespace std;
int block;
struct EiEi{
    int l,r,idx;
    bool operator < (EiEi &a){
        if(l / block == a.l / block)
            return ((l / block)&1)? r > a.r: r < a.r;
        return l / block < a.l / block;
    }
};
int n,t,cnt;
int arr[50001], num[50001];
unordered_map<int,int> mp;
vector<int> v;
void add(int i){
    num[v[i]]++;
    if(num[v[i]] >= 2) cnt++;
}
void del(int i){
    num[v[i]]--;
    if(num[v[i]] >= 1) cnt--;
}
void solve(EiEi q[],int ans[]){
    sort(q,q+t);
    int l=0, r=-1;
    for(int i=0; i<t; i++){
        while(r < q[i].r) add(++r);
        while(r > q[i].r) del(r--);
        while(l > q[i].l) add(--l);
        while(l < q[i].l) del(l++);
        ans[q[i].idx] = cnt;
    }
    for(int i=0; i<t; i++) cout << ans[i] << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i], v.push_back(arr[i]);
    for(int i=0; i<n; i++){
        if(!mp.count(v[i]))
            mp[v[i]] = i;
        v[i] = mp[v[i]];
    }
    
    cin>>t;
    EiEi q[t];
    int ans[t];
    for(int i=0; i<t; i++){
        cin>>q[i].l>>q[i].r;
        q[i].idx = i;
    }
    
    block = ceil(sqrt(n));
    solve(q,ans);
    return 0;
}