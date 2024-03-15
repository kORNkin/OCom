#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long m,n; cin>>m>>n;
    long long arr[m];
    for(auto &x:arr) cin>>x;
    long long l=1,r=1e12;
    while(l<r){
        long long mid = (l+r) >> 1, sum=0;

        for(int i=0;i<m;i++) sum+= mid / arr[i];

        if(sum >= n) r = mid;
        else l = mid+1; 
    }
    cout << l;

    return 0;

}