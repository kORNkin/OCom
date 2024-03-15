#include<bits/stdc++.h>
using namespace std;

int n, k, ans, arr[500001];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    deque<pair<int,int>> dq;
    for(int i = 0; i < n; i++){
        while(!dq.empty() && i - dq.front().first > k) dq.pop_front();
        if(!i) ans = arr[i];
        else ans = dq.front().second + arr[i];
        while(!dq.empty() && ans <= dq.back().second) dq.pop_back();
        dq.push_back({i, ans});
    }
    cout << ans;

    return 0;
}

