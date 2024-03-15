#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
using namespace std;

const int block = 900;

struct EiEi{
    int l,r,idx;
    bool operator < (EiEi &a) {
        if(l / block == a.l / block)
            return ((l / block)&1)? r > a.r : r < a.r;
        return l / block < a.l / block;
    }
};

int n,t;
long long sum, ans[200001];
int arr[200001], mp[1000001];
EiEi q[200001];
void add(int i){
    i = arr[i];
    sum += i * (2ll * mp[i] + 1);
    mp[i]++;
}

void del(int i){
    i = arr[i];
    sum -= i * (2ll * mp[i] - 1);
    mp[i]--;
}

void solve(){
    sort(q,q+t);

    int l = 0, r = -1;
    for(int i=0; i<t; i++){
        while(r < q[i].r) add(++r);
        while(r > q[i].r) del(r--);
        while(l > q[i].l) add(--l);
        while(l < q[i].l) del(l++);
        ans[q[i].idx] = sum;
    }

    for(int i=0; i<t; i++)
        cout << ans[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> t;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<t; i++){
        cin >> q[i].l >> q[i].r;
        q[i].l--; q[i].r--;
        q[i].idx = i;
    }

    solve();

    return 0;
}