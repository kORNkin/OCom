#include<bits/stdc++.h>
using namespace std;

int n, q, a, b;
class bit{
    int fw[100001];

    public: 
        void upd(int i, int val) {
            for(; i <= n; i += i & -i) fw[i] += val;
        }

        int qur(int i) {
            int res = 0;
            for(; i > 0; i -= i & -i) res += fw[i];
            return res;
        }

        int up(int val){
            int l = 1, r = n + 1;
            while(l < r){
                int m = (l + r) >> 1;
                if(qur(m) > val) l = m + 1;
                else r = m; 
            }
            return l;
        }
} fw;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q >> a >> b;
    //a = 70, b = 80; 
    fw.upd(n + 1, -1e9);
    while(q--){
        int d, x, c; cin >> d >> x >> c;
        if(d == 1){
            fw.upd(1, c);
            fw.upd(x + 1, -c);
        }else { 
            fw.upd(x, -c);
        }
        int l = fw.up(b);
        int r = fw.up(a - 1) - 1;
        int ch = fw.qur(r);
        if(ch < a || ch > b ) cout << "-1\n";
        else if(l != r) cout << l << ' ' << r << '\n';
        else cout << l << '\n';
    }   

    return 0;
}
