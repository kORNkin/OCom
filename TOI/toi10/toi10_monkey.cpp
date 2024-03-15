#include<bits/stdc++.h>
using namespace std;

int m, n, k, p, arr[200001];
bool can[200001];
vector<pair<int, int>> evn;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
   
    cin >> m >> n >> k;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= k; i++){
        int idx, w; cin >> idx >> w;
        evn.push_back({w, idx});
    }
    cin >> p;
    can[p] = can[p - 1] = can[p + 1] = 1;
    sort(evn.begin(), evn.end());
    for(auto &[w, idx] : evn){
        swap(can[idx], can[idx + 1]);
        if(idx == p) ++p;
        else if(idx + 1 == p) --p;
        can[p] = can[p - 1] = can[p + 1] = 1;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) if(can[i]) ans = max(ans, arr[i]);
    cout << ans << '\n' << (ans == arr[p]? "NO": "USE");

    return 0;
}