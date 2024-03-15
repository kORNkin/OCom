#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int,int>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    pii arr[n];   
    for(int i=0;i<n;i++)
        cin>>arr[i].first>>arr[i].second;
    sort(arr,arr+n,[&](pii a,pii b){
        return a.s < b.s;
    });
    int cnt=0;
    int curr=0;
    for(pii e:arr){
        if(e.f < curr) continue;
        curr = e.s;
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}