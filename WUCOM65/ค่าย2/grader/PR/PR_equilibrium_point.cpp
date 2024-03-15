#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        int arr[n+1],qs[n+2];
        memset(qs,0,sizeof(qs));
        for(int i=1;i<=n;i++) cin>>arr[i], qs[i] = qs[i-1]+arr[i];
        //int x=1;
        for(int i=1;i<=n;i++){
            if(qs[i-1] == qs[n]-qs[i]){
                cout<<i<<'\n'; break;
            }
        }
    }

    return 0;
}