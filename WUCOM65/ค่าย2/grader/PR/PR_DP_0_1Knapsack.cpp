#include <bits/stdc++.h>
using namespace std;
int n,W,mx=0;
pair<int,int> arr[1001];

void bcounter(int idx,int sumw,int sumv){
    if(sumw>W) return;
    mx = max(sumv,mx);
    if(idx == n) return;

    bcounter(idx+1,sumw,sumv);
    bcounter(idx+1,sumw+arr[idx].second,sumv+arr[idx].first);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;cin>>T;
    while(T--){
        cin>>n>>W;
        for(int i=0;i<n;i++)
            cin>>arr[i].first;
        for(int i=0;i<n;i++){
            cin>>arr[i].second;
        }

        mx=0;
        bcounter(0,0,0);
        cout << mx << '\n';
    }

    return 0;
}