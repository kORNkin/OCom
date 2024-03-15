#include<bits/stdc++.h>
using namespace std;

struct E{
    int u, v, l = -1, r = -1;
    int in_range = 0;
    void set(int a, int b) {
        l = a;
        r = b;
    }
    E() {}
    E(int u1, int v1, int l1, int r1, int inr) {
        u = u1;
        v = v1;
        l = l1;
        r = r1;
        in_range = inr;
    }
};

struct Q{
    int op, a, b, c;
    Q() {}
    Q(int op1, int a1, int b1, int c1){
        op = op1;
        a = a1;
        b = b1;
        c = c1;
    }
};

int n, m, k, q, par[100001], sz[100001];
vector<E> edges;
vector<Q> qt;
unordered_set<int> nodes, all_sz;
int member_cnt[100001];
int cnt[1000];
int ans[100001];

int findP(int i, int p){
    return (i == p ? i : par[i] = findP(p, par[p]));
}

void uni(int a, int b){
    a = findP(a, par[a]);
    b = findP(b, par[b]);
    if(a == b) return;

    if(sz[a] < sz[b]) par[a] = b;
    else {
        par[b] = a;
        if(sz[a] == sz[b]) sz[a]++;
    }
}

bool chk(int a, int b) { return findP(a, par[a]) == findP(b, par[b]); }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k >> q;

    for(int i = 0; i < k; i++) {
        int x; cin >> x;
        member_cnt[x]++;
        nodes.insert(x);
    }

    for(auto node : nodes){
        all_sz.insert(member_cnt[node]);
        cnt[member_cnt[node]]++;
    }

    while(m--){
        int u, v; cin >> u >> v; 
        edges.push_back(E(u, v, -1, -1, 0));
    }

    for(int i = 0; i < q; i++){
        int op; cin >> op; op--;
        if(op) {
            int s, e; cin >> s >> e;
            qt.push_back(Q(op, s, e, -1));
        } else {
            int p, l, r; cin >> p >> l >> r; 
            qt.push_back(Q(op, p - 1, l, r));
        }
    }

    reverse(qt.begin(), qt.end());

    for(int range : all_sz){
        //cout << "range: " << range << " amount: " << cnt[range] << '\n';

        //reset dsu
        for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 0;


        int in_range = 0;
        for(Q &coms : qt){
            if(!coms.op){
                if(range >= coms.b && range <= coms.c) edges[coms.a].in_range++;
                edges[coms.a].set(coms.b, coms.c);
            }
        }

        for(E &e : edges){
            if(range >= e.l && range <= e.r) continue;
            uni(e.u, e.v);
        }
        
        int idx = 0;
        for(Q &coms : qt){
            if(!coms.op){
                if(edges[coms.a].in_range > 1) edges[coms.a].in_range--;
                else {
                    edges[coms.a].in_range--;
                    uni(edges[coms.a].u, edges[coms.a].v);
                }
                
            } else {
                if(chk(coms.a, coms.b)){
                    ans[idx] += cnt[range];
                    //cout << "idx: " << q - idx - 1 << " range: " << range << " coms: " << coms.a << " , " << coms.b << " ans: " << ans[idx] << '\n'; 
                }
            }
            idx++;
        }

        for(E &e : edges){
            e.in_range = 0;
        }
    }

    for(int i = q - 1 ; i >= 0; i--){
        if(qt[i].op) cout << ans[i] << '\n';
    }

    return 0;
}
