#include<bits/stdc++.h>
using namespace std;

int n, m, dp[3001];
pair<int, int> arr[3001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i].first, arr[i].second = i;
    sort(arr, arr + n);

    int l = 1, r = n - 1;
    while(l < r){
        int k = (l + r) >> 1;

        int mx = 0;
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(arr[i].first == arr[j].first) continue;

                int dis = arr[j].second - arr[i].second;
                if(dis < 0) dis += n;
                if(dis <= k) dp[j] = max(dp[j], dp[i] + 1);
            }
        }

        for(int i = 0; i < n; i++) mx = max(mx, dp[i]);

        if(mx < m) l = k + 1;
        else r = k;
    }
    cout << l;

    return 0;
}