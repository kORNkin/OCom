#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

int n, q;

class BIT{
    int fw[N];

    public: 
        void upd(int i, int val){
            for(; i <= n; i += i & -i) fw[i] += val;
        }

        int qur(int i){
            int res = 0;
            for(; i > 0; i -= i & -i) res += fw[i];
            return res;
        }

        int sum(int l, int r) { return qur(r) - qur(l - 1); }

} evn, odd;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) { int x; cin >> x; evn.upd(i, ~x&1), odd.upd(i, x&1); }

    cin >> q;
    while(q--){
        int op, a, b; cin >> op >> a >> b;
        if(!op) evn.upd(a, ~b&1), odd.upd(a, b&1);
        else if(op ^ 2) cout << evn.sum(a, b) << '\n';
        else cout << odd.sum(a, b) << '\n';
    }

    return 0;
}