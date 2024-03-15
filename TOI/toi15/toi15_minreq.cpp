#include<bits/stdc++.h>
using namespace std;

int n, m, x, lf[11], stf[11], t[11], q[11], qs[10000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;
    for(int i = 1; i <= n; i++) cin >> lf[i];
    for(int i = 1; i <= n; i++) cin >> stf[i];
    for(int i = 1; i <= m; i++) cin >> qs[i], qs[i] += qs[i - 1];
    for(int i = 1; i <= x; i++) cin >> t[i];
    sort(lf + 1, lf + n);
    sort(stf + 1, stf + 1 + n);
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++) cin >> q[j]; q[n] = m;
        bool can;
        do {
            can = 1;
            for(int j = 1; j <= n && can; j++){
                int idx = q[j - 1], cnt = 0;
                while(idx < q[j]){
                    idx = upper_bound(qs + 1, qs + 1 + m, lf[j] - stf[j] + qs[idx - 1]) - qs;
                    if(++cnt > t[i]) { can = 0; break; }
                }
            }
        }while(next_permutation(stf + 1, stf + 1 + n) && !can);
        cout << (can? "P\n": "F\n");
    }

    return 0;
}