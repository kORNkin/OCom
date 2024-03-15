#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;

ll n, q, arr[N];

struct Node {
    ll sum, l, r, ans;

    Node () {}
    Node (ll val) {
        sum = l = r = ans = val;
    }
};

class st{
    Node seg[N * 4];

    private: 
        Node cal(Node a, Node b) { 
            Node tmp;
            tmp.sum = a.sum + b.sum;
            tmp.l = max(a.l, a.sum + b.l);
            tmp.r = max(b.r , b.sum + a.r);
            tmp.ans = max({a.ans, b.ans, a.r + b.l});
            return tmp;
        } 

    public: 
        void build(ll l, ll r, ll L, ll R, ll node) {
            if(l > R || r < L) return;  
            if(l == r) {
                seg[node] = Node(arr[l]);
                return;
            }

            ll m = (l + r) >> 1;   
            build(l, m, L, R, node * 2);
            build(m + 1, r, L, R, node * 2 + 1);
            seg[node] = cal(seg[node << 1], seg[node << 1 | 1]);
        } 

        void upd(ll l, ll r, ll pos, ll node, ll val){ 
            if(l == r) {
                seg[node] = Node(val);
                return;
            }

            ll m = (l + r) >> 1;

            if(pos <= m) upd(l, m, pos, node * 2, val);
            else upd(m + 1, r, pos, node * 2 + 1, val);

            seg[node] = cal(seg[node << 1], seg[node << 1 | 1]);
        } 

        Node qur(ll l, ll r, ll L, ll R, ll node) { 
            if(l > R && r < L) return Node(-1e9);
            if(l >= L && r <= R) return seg[node];

            ll m = (l + r) >> 1;

            return cal(qur(l, m, L, R, node * 2), qur(m + 1, r, L, R, node * 2 + 1));

            //return seg[1].ans //faster
        } 

} seg; 

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    seg.build(1, n, 1, n, 1);
    cout << seg.qur(1, n, 1, n, 1).ans << '\n';

    while(q--){
        ll a, b; cin >> a >> b;
        seg.upd(1, n, a + 1, 1, b);
        cout << seg.qur(1, n, 1, n, 1).ans << '\n';
    }

    return 0;
}
