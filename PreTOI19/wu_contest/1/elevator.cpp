#include<bits/stdc++.h>
using namespace std;
struct P{
    long long cnt, w;
};
int n, mxw, w[20], idx[20];
vector<P> dp(1<<20);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //cout << bitset<8>(2).to_string();

    cin >> n >> mxw;

    for(int i = 1; i <= (1 << n); i++) dp[i] = {(long long)1e18, (long long)1e18};

    for(int i = 0; i < n; i++) cin >> w[i], dp[1 << i] = {1, w[i]};
    

    dp[0] = {0, 0};
    for(int i = 1; i <= (1 << n) - 1; i++){
        for(int j = 1; j < i; j <<= 1){
            if(i & j) {
                P tmp;
                tmp.w = dp[i ^ j].w + dp[j].w;
                tmp.cnt = max(dp[i ^ j].cnt, dp[j].cnt);
                if(tmp.w > mxw) tmp.cnt++,  tmp.w = min(dp[i ^ j].w, dp[j].w);

                if(dp[i].cnt > tmp.cnt){
                    dp[i] = tmp;
                }else if(dp[i].cnt == tmp.cnt) dp[i].w = min(dp[i].w, tmp.w);
                //cout << bitset<4>(i).to_string() << " = " << bitset<4>(i ^ j).to_string() << " & " << bitset<4>(j).to_string() << " --> ( " << tmp.cnt << ", " << tmp.w << " )\n";  
            }
        }
    }

    cout << dp[(1 << n) - 1].cnt;

    return 0;
}
