#include<bits/stdc++.h>
using namespace std;

int n, tar, ans[300001], qs[300001];
pair<int ,int> ss[300001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        ss[i] = {x, i};
        tar += x;
    } 
    sort(ss + 1, ss + 1 + n, greater<pair<int ,int>>());
    for(int i = 1; i <= n; i++){
        qs[i] = ss[i].first + qs[i - 1];
    }
    tar >>= 1;
    for(int i = 1; i <= n; i++){
        ans[ss[i].second] = upper_bound(qs + 1, qs + 1 + n, tar - ss[i].first) - qs;
        if(ans[ss[i].second] >= i){
            ans[ss[i].second] = upper_bound(qs + 1, qs + 1 + n, tar) - qs - 1;
        }
    }
    for(int i = 1 ; i <= n; i++) cout << ans[i] << '\n';

    return 0;
}