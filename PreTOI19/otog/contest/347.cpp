#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m;
    cin>>n>>m;
    long long arr[n]; 
    memset(arr,0,sizeof(arr));
    while(m--){
        char c; cin>>c;
        long long p,s; cin>>p;
        if(c=='B'){
            cin>>s;
            arr[p-1] = max(arr[p-1],s);
        }else{
            long long mx=0;
            for(int i=0;i<p;i++)
                mx = max(mx,arr[i]);
            cout << mx << "\n";
        }
    }

    return 0;
}
