#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

    long long n,m; cin>>n>>m;
    long long arr[m];
    for(int i=0;i<m;i++) cin>>arr[i];

    long long l=0, r=n;
    while(l < r){
        long long mid = floor((l+r)/2.0);
        
        long long mn=1e9,mx=0;
        bool ch=0;
        for(int i=0;i<m;i++){
            mn = min(mn,arr[i]-mid);
            if(!mx) mx = arr[i]+mid;
            else if(mx+1 < arr[i]-mid){
                ch=1;
                break;
            }
            mx = max(arr[i]+mid,mx);
        }
        if(ch || mn > 1 || mx < n) l = mid+1;
        else r = mid;
    }
    cout << l;

    return 0;
}
