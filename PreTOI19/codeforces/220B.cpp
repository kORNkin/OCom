#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
using namespace std;
const int block = 350;
struct EiEi{
    int l,r,idx;
    bool operator < (EiEi &a){
        if(l / block == a.l / block)
            return r < a.r;
        return l / block < a.l / block;
    }
};
int n,m,cnt; 
int arr[100001], ans[100001];
int mp[100001];
EiEi q[100001];

void add(int i){
    i = arr[i];
    if(i > n) return;
    if(mp[i] == i) cnt--;
    mp[i]++;
    if(mp[i] == i) cnt++;
}

void del(int i){
    i = arr[i];
    if(i > n) return;
    if(mp[i] == i) cnt--;
    mp[i]--;
    if(mp[i] == i) cnt++;
}

void solve(){
    sort(q,q+m);
    int l = 0,r = -1;
    for(int i=0;i<m;i++){
        while(r < q[i].r) add(++r);
        while(r > q[i].r) del(r--);
        while(l > q[i].l) add(--l);
        while(l < q[i].l) del(l++);     
        ans[q[i].idx] = cnt;
    }

    for(int i=0; i<m; i++)
        cout << ans[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<m; i++){
        cin>>q[i].l>>q[i].r;
        q[i].l--; q[i].r--;
        q[i].idx = i;
    }
    solve();

    return 0;
}