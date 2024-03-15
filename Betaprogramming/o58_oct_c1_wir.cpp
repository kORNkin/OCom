#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[100001];
stack<pair<int,int>> st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        while(!st.empty() && st.top().second > x) st.pop();
        if(!st.empty()) dp[i] = max(dp[st.top().first] , x - st.top().second);
        st.push({i,x});
    } 
    sort(dp,dp+n);

    while(m--){
        int x; cin>>x;
        auto it = dp+n-upper_bound(dp,dp+n,x);
        cout << it << '\n';
    }

    return 0;

}