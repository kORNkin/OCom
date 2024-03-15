#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        ll n, mx = 0; cin >> n;
        stack<ll> st;
        ll h[n + 1]; h[n] = 0;
        for(int i = 0; i < n; i++) cin >> h[i];
        for(int i = 0; i <= n; i++){
            while(!st.empty() && h[st.top()] > h[i]){
                int idx = st.top(); st.pop();
                if(st.empty()) mx = max(mx, i * h[idx]);
                else mx = max(mx, (i - st.top() - 1) * h[idx]);
            }
            st.emplace(i);
        }
        cout << mx << '\n';
    }

    return 0;
}