#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
#define f first 
#define s second
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while(T--){
        int n,mx=0; cin>>n;
        pii arr[n];
        for(int i=0;i<n;i++){
            int x; cin>>x;
            cin >> arr[i].s >> arr[i].f;
        }
        sort(arr,arr+n,greater<pii>());
        bitset<101> vis(0);
        int cnt=0,sum=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].s;j>0;j--){
                if(!vis[j]){
                    cnt++; sum+=arr[i].f;
                    vis[j]=1;
                    break;
                }
            }
        } cout << cnt << " " << sum << '\n';
    }
    
    return 0;
}