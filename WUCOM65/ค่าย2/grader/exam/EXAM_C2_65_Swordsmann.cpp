#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    int n; cin>>n;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end(),greater<pair<int,int>>());

    int mx=0,cnt=0;
    for(int i=0;i<n;i++){
        if(mx >= arr[i].second) continue;
        mx = arr[i].second;
        cnt++;
    } 
    cout << cnt;
    
    return 0;
}
