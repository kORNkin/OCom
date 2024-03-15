#include<bits/stdc++.h>
using namespace std;
int arr[] = {2, 4, 1, 9, 7, 8, 5, 10, 12};
int par[10001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n = sizeof(arr)/ sizeof(arr[0]);

    //O(n^2) + path
    cout << "O(n^2):\n";

    int dp[n+1];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<n;i++) par[i] = i; 

    int mx = 0, idx = 0;
    for(int i=0;i<n;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(arr[j] < arr[i]){
                if(dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    par[i] = j;
                }
            }
        }

        if(mx < dp[i]) {
            mx = dp[i]; idx = i;
        }
    }

    cout << mx << '\n';
    vector<int> ans;
    int i;
    for(i = idx ; i != par[i]; i = par[i]) ans.push_back(arr[i]);
    ans.push_back(arr[i]);
    for(int i = ans.size()-1; i>=0; i--) cout << ans[i] << ' ';

    //-------
    cout << "\n----------\n";
    //-------

    //O(nlogn) + path
    cout << "O(nlogn):\n";

    vector<int> v;
    unordered_map<int,int> mp; 
    for(int i=0;i<n;i++) par[i] = i, mp[arr[i]] = i;


    for(int i=0;i<n;i++){
        if(v.empty() || v.back() < arr[i]) {
            v.push_back(arr[i]);
            if(v.size()==1) par[mp[v.back()]] = mp[v.back()];
            else par[mp[v.back()]] = mp[v[v.size()-2]];
        }
        else {
            auto it = lower_bound(v.begin(),v.end(), arr[i]);
            *it = arr[i];
            int idx = it - v.begin();
            par[mp[v[idx]]] = mp[v[idx-1]];
        }
    }

    cout << v.size() << '\n';
    vector<int> ans2;
    int cnt = 0;
    for(int i = mp[v.back()] ; i != par[i] || cnt < v.size() ; i = par[mp[arr[i]]], cnt++) ans2.push_back(arr[i]);
    for(int i=ans2.size()-1; i>=0; i--) cout << ans2[i] << ' ';

    return 0; 
}