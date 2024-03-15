#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    int n,m; cin>>n>>m;
    int arr[m];
    for(int i=0;i<m;i++) cin>>arr[i];
    sort(arr,arr+m);
    int sum=0,mx=0;
    for(int i=0;i<m;i++){
        sum+=arr[i];
        if(sum > n){
            mx=i; break;
        }else if(sum==n){
            mx=i+1; break;
        }else if (i==m-1 && sum <= n){
            mx=m;
        }
    } cout << mx;
    
    return 0;
}