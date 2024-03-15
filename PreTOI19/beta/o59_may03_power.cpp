#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
using namespace std;

#define ll long long
const int block = 225;

struct EiEi{
    int l,r,idx;
    bool operator < (EiEi &a){
        if(l / block == a.l / block)
            return ((l / block)&1)? r > a.r: r < a.r;
        return l / block < a.l / block;
    }
};

int n,t,p;
ll sum;
int arr[80001], ans[50001];
int mp[1000001];
EiEi q[50001];

ll poww(int a,int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    ll x = poww(a,b/2);
    if(b&1) return x%p * x%p * a;
    return x%p * x%p;
}

void add(int i){
    i = arr[i];
    sum -= mp[i] * poww(i,mp[i]);
    mp[i]++;
    sum += mp[i] * poww(i,mp[i]);
}

void del(int i){
    i = arr[i];
    sum -= mp[i] * poww(i,mp[i]);
    mp[i]--;
    sum += mp[i] * poww(i,mp[i]);
}

void solve(){
    sort(q,q+t);

    int l = 0, r = -1;
    for(int i=0; i<t; i++){
        while(r < q[i].r) add(++r);
        while(r > q[i].r) del(r--);
        while(l > q[i].l) add(--l);
        while(l < q[i].l) del(l++);
        ans[q[i].idx] = sum%p;
    }
    
    for(int i=0; i<t; i++) cout << ans[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>t>>p; 
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<t; i++){
        cin>>q[i].l>>q[i].r;
        q[i].l--; q[i].r--;
        q[i].idx = i;
    }
    solve();

    return 0;
}