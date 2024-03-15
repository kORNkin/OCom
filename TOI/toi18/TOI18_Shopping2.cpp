#include<bits/stdc++.h>
using namespace std;
int n,m;
int pqs[500001], nqs[500001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(x >= 0) nqs[i] = nqs[i-1], pqs[i] = pqs[i-1] + x;
        else nqs[i] = nqs[i-1] + abs(x), pqs[i] = pqs[i-1];
    }

    while(m--){
        int idx,h; cin >> idx >> h;
        idx++;
        int it = lower_bound(nqs + 1, nqs + n + 1, h + nqs[idx-1]) - nqs;
        cout << pqs[it-1] - pqs[idx-1] << '\n';
    }
    return 0;
}