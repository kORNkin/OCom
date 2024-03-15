#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m,n; cin>>m>>n;
    vector<long long int> ans;
    pair<int,int> arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i].first;
        arr[i].second = arr[i].first;
        ans.push_back(0);
    }
    sort(arr,arr+m);
    while(ans.size()<=n){
        long long int mn= LLONG_MAX;
        sort(arr,arr+m);
        for(int i=0;i<m;i++){
            if(mn>=arr[i].first){
                mn=arr[i].first;
                arr[i].first+=arr[i].second; 
                ans.push_back(mn);
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<n;i++){
        cout << ans[i] << '\n';
    }
    
    return 0;
}

