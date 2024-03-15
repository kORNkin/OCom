#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    int arr[n],dp[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[i]=arr[i];
        for(int j=i-2;j>=0;j--){
            dp[i]=max(dp[i],arr[i]+dp[j]);
        }
    }
    int q; cin>>q;
    while(q--){
        int x; cin>>x;
        int ch=0;
        for(int i=0;i<n;i++){
            if(dp[i] >= x) {
                ch=i+1;
                break;
            }
        }
        if(ch) cout << ch << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}