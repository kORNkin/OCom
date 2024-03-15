#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int n, m, cnt;
int par[600002], sz[600002];
long long pw[300001];
bool ch;

int findP(int i, int p) { return (i == p ? i : par[i] = findP(p, par[p])); }

void uni(int a, int b) {
    a = findP(a, par[a]);
    b = findP(b, par[b]);
    if(a == b) return;
    cnt--;
    if(sz[a] < sz[b]) par[a] = b;
    else {
        par[b] = a;
        if(sz[a] == sz[b]) sz[a]++;
    }
}

bool chk(int a, int b){ return findP(a, par[a]) == findP(b, par[b]); }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m; cnt = n << 1;
    for(int i = 1; i <= n << 1; i++) par[i] = i;

    pw[0] = 1;
    for(int i = 1; i <= n; i++) pw[i] = (pw[i - 1] << 1) % M;

    while(m--){
        int op, x, y; cin >> op >> x >> y;

        if(ch) {
            cout << "0\n";
            continue;
        }

        if(op) uni(x, y), uni(x + n, y + n);
        else uni(x, y + n), uni(y, x + n);
        
        if(chk(x, x + n) || chk(y, y + n)) ch = 1, cout << "0\n";
        else cout << pw[cnt>>1] << '\n';
    }

    return 0;
}