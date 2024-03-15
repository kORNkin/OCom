#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n,q; cin>>n>>q;
    long long arr[n]; 
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<long long> lis,rev,ans;
    for(int i=0;i<n;i++){
        if(lis.empty() || lis.back() < arr[i]){
            lis.push_back(arr[i]);
            ans.push_back(lis.size());
        }
        else {
            auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
            *it = arr[i];
            ans.push_back(it-lis.begin()+1);
        }
        
    }
    for(int i=n-1;i>=0;i--){
        if(rev.empty() || rev.back() < arr[i]){
            rev.push_back(arr[i]);
            ans[i]=min(ans[i],(long long)rev.size());
        }
        else {
            auto it = lower_bound(rev.begin(),rev.end(),arr[i]);
            *it = arr[i];
            ans[i]=min(ans[i],(long long)(it-rev.begin())+1);
        }
        
    }
    
    while(q--){
        long long n; cin>>n;
        cout << ans[n]-1 << '\n';
    }

    return 0;
}
/*
14 3
1 3 4 6 7 9 7 5 6 7 2 5 3 2
2 3 4
*/