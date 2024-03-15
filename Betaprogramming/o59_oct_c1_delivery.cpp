#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1<<17;
int k, L, Q, sz;
vector<pair<int, int>> gate;
int tree[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> L >> Q;
    sz = 1<<k;

    for(int i = )

    while(L--){
        int u, v; cin >> u >> v;
        if(u > v) swap(u, v);
        gate.emplace_back(u, v);
    }
    while(Q--){
        int u, v; cin >> u >> v;
        if(u > v) swap(u, v);
    }

    return 0;
}