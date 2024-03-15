#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define f first
#define s second

ll n, l, r, sum, ans;
pair<ll, ll> arr[5000001];
deque<pair<ll, ll>> dq;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> l >> r;
    for(int i = 1; i <= n; i++) cin >> arr[i].second;
    for(int i = 1; i <= n; i++) cin >> arr[i].first;

    /*arr[0].second = arr[1].second - 1;
    dq.push_back({0, 0});
    for(int i = 1; i <= n; i++){
        sum += arr[i].f;
        while(!dq.empty() && arr[i].s - arr[dq.front().s + 1].s >= r) dq.pop_front();
        while(!dq.empty() && ans > sum - dq.back().f) dq.pop_back();
        dq.push_back({sum, i});

        if(ans < sum - dq.front().f && arr[i].s - arr[dq.front().s + 1].s > l){
            ans = sum - dq.front().f;
        }

        for(auto p : dq){
            cout << p.second << ' ';
        } cout << '\n';
        cout << "ans : " << ans << '\n';
    }
    */

    /*
    pq.push({0, 0});
    for(int i = 1; i <= n; i++){
        sum += arr[i].first;
        while(!pq.empty() && arr[i].second - arr[pq.top().second + 1].second > l) pq.pop();
        while(!pq.empty() && ans >= sum - pq.top().first) pq.pop();
        pq.push({sum, i});

        if(ans < sum - pq.top().first && arr[i].second - arr[pq.top().second + 1].second >= s){
            ans = sum - pq.top().first;
            cout << arr[i].second << ' ' << arr[pq.top().second + 1].second << '\n'; 
        }
        //cout << sum - pq.top().first << '\n';
    }*/

    ll cur, mx, st;
    mx = st = 0;
    cur = arr[0].second - 1;
    for(int i = 1; i <= n; i++){
        mx += arr[i].first;
        if(mx < arr[i].first) mx = arr[i].first;

        if(st < mx && arr[i].second - cur + 1 >= l  && arr[i].second - cur < r){
            st = mx;
            cur = arr[i].second;
        }
    }


    cout << st;

    return 0;
}
