#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200001;
const int sz = ceil(sqrt(200001));
ll n, q;
array<ll, N> arr;
array<ll , sz> cluster;

void build(){
    for(int i = 0; i < n; i++){
        cluster[i / sz] += arr[i];
    }
}

void upd(int i, int val){
    arr[i] = val;
    int l = (i / sz) * sz;
    int r = min(n - 1, (ll)l + sz - 1);
    cluster[l / sz] = 0;
    for(int j = l; j <= r; j++)
        cluster[j / sz] += arr[j];
}

ll qur(int l, int r){
    ll res = 0;
    while(l <= r && l % sz != 0){
        res += arr[l];
        l++;
    }

    while(l + sz - 1 <= r && l % sz == 0){
        res += cluster[l / sz];
        l += sz;
    }

    while(l <= r){
        res += arr[l];
        l++;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build();

    while(q--){
        ll op, a, b; cin >> op >> a >> b;
        if(op ^ 1) cout << qur(a - 1, b - 1) << '\n';
        else upd(a - 1, b);
    }

    return 0;
}