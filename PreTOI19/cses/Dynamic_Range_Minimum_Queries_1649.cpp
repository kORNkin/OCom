/*
//segment tree
#include<bits/stdc++.h>
using namespace std;

int n, q, seg[400001];

void upd(int i, int &val){
    for(seg[i += n] = val; i > 1; i >>= 1) seg[i >> 1] = min(seg[i], seg[i ^ 1]);
}

int qur(int &l, int &r){
    int res = 1e9;
    l--, r--;
    for(l += n, r += n; l <= r; l >>= 1, r >>= 1){
        if(l&1) res = min(res, seg[l++]);
        if(~r&1) res = min(res, seg[r--]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> seg[i + n];
        upd(i, seg[i + n]);
    }
    while(q--){
        int op, a, b;
        cin >> op >> a >> b;
        if(op ^ 1) cout << qur(a, b) << '\n';
        else upd(a - 1, b); 
    }


    return 0;
}
*/

//sqrt decomposition
#include<bits/stdc++.h>
using namespace std;
const int N = 200001, sz = ceil(sqrt(N));
int n, q;

int arr[N];
int cls[sz];

void build(){
    int cls_sz = ceil(N / sz);
    for(int i = 0; i < cls_sz; i++){
        cls[i] = 1e9;
    }
    for(int i = 0; i < n; i++)
        cls[i / sz] = min(cls[i / sz], arr[i]);
}

void upd(int i, int val){
    arr[i] = val;
    int l = (i / sz) * sz;
    int r = l + sz;
    cls[l / sz] = 1e9;
    for(int i = l; i <= r; i++){
        cls[i / sz] = min(cls[i / sz], arr[i]); 
    }
}

int qur(int l, int r){
    int res = 1e9;
    while(l <= r && l % sz != 0){
        res = min(res, arr[l]);
        l++;
    }

    while(l + sz - 1 <= r && l % sz == 0){
        res = min(res, cls[l / sz]);
        l += sz;
    }

    while(l <= r){
        res = min(res, arr[l]);
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

    while(q--) {
        int op, a, b; cin >> op >> a >> b;
        if(op ^ 1) cout << qur(a - 1, b - 1) << '\n';
        else upd(a - 1, b);
    }   

    return 0;
}