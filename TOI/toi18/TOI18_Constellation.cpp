/*
Author: kornkin.png
Algor: Quick sum + DP(cnr)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int mod = 1000003;
int r, c, k, kk;
int tl[4001][4001],tr[4001][4001];
ll dp[801][801];
ll fac[801];
char g[4001][2001];

ull poww(ull a,ull b){
    if(b == 0) return 1;
    if(b == 1) return a;

    ull x = poww(a, b / 2)%mod;
    if(b&1) return x%mod * x%mod * a%mod;
    else return x%mod * x%mod;
}

ll cnr(ll sum, ll kk){
    ull a = 1, b = 1;
    int mx = max(kk, sum-kk);
    int mn = min(kk, sum-kk);
    bitset<701> vis(0);
    //cout << "cnr: " << sum << "," << kk << " = ";
    for(int i = mx+1; i<=sum; i++){
        a *= i;
        a%=mod;
    }
    for(int j = 2; j <= mn; j++){
        //b *= j;
        a *= poww(j,mod-2)%mod;
        a %= mod;
    }
    //if(b > 1)b = poww(b,mod-2)%mod;
    //cout << "cnr: " << sum << "," << kk << "-->" << a << " / " << b << " = "<< a << '\n';
    return dp[sum][kk] = (ull)(a)%mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    /*fac[0] = 1;
    for(int i = 1; i <= 700; i++){
        fac[i] = fac[i-1]*i;
        fac[i] %= mod;
        cout << i << " :" << fac[i] << '\n';
    }*/

    cin >> r >> c >> kk;
    k = r + c;
    r += k;
    c += k;

    for(int i = k + 1; i <= r ;i++){
        for(int j = k + 1; j <= c;j++){
            cin >> g[i][j]; 
        }
    }

    for(int i = k + 1; i <= r + k; i++){
        for(int j = k + 1; j <= c + k; j++){
            if(i <= r && j <= c && g[i][j] ^ '.') tl[i][j] = tl[i-1][j-1] + 1;
            else tl[i][j] = tl[i-1][j-1];
        }
    }

    for(int i = k + 1; i <= r + k ; i++){
        for(int j = c; j >= 1; j--){
            if(i <= r && j >= k + 1 && g[i][j] ^ '.') tr[i][j] = tr[i-1][j+1] + 1;
            else tr[i][j] = tr[i-1][j+1]; 
        }
    }

    /*for(int i = 1; i <= r + k ;i++){
        for(int j = 1; j <= c + k;j++){
            cout << tl[i][j] << ' ' ;
        } cout << '\n';
    }

    cout << '\n';

    for(int i = 1; i <= r + k ;i++){
        for(int j = 1; j <= c + k;j++){
            cout << tr[i][j] << ' ';
        } cout << '\n';
    }*/

    ll ans = 0;
    for(int l = 1; l <= r + c - k - k - 1; l++){
        ///cout << "---" << l << "---\n";
        for(int x = k + 1; x <= r; x++){
            for(int y = k + 1; y <= c; y++){
                ll sum = 0;
                sum += tl[x + l][y] - tl[x-1][y- l -1];
                sum += tl[x][y + l] - tl[x- l -1][y-1];
                sum += tr[x-1][y- l +1] - tr[x - l][y];
                sum += tr[x+ l -1][y + 1] - tr[x][y + l];
                //cout << sum << ' ';

                if(sum == kk) ans++;
                else if(sum > kk) {
                    if(dp[sum][kk]) ans += dp[sum][kk];
                    else ans += cnr(sum,kk);
                }
                ans%=mod;
            } //cout << '\n';
        }
    }

    cout << ans%mod;

    return 0;
}
/*
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 1 0 1 0 0 0 
0 0 1 0 2 0 1 0 0 
0 0 0 2 0 3 0 1 0 
0 0 1 0 3 0 3 0 1 
0 0 0 2 0 4 0 3 0 
0 0 0 0 2 0 4 0 3 
0 0 0 0 0 2 0 4 0
0 0 0 0 0 0 2 0 4
*/