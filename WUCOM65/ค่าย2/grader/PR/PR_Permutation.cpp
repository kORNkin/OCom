#include <bits/stdc++.h>
using namespace std;
int n,k,l,cnt=0;
bool ch=0;
bool vis[100001];
void solve(int kk,int arr[],int idx){
    if(ch) return;
    if(kk>k) return;
    if(kk==k){
        cnt++;
        if(l==cnt) {
            for(int i=0;i<idx;i++) cout << arr[i] << ' ';
            cout << '\n';
            ch=1;
        }
        return;
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            arr[idx]=i;
            vis[i]=1;
            solve(kk+1,arr,idx+1);
            vis[i]=0;
        }
    }
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k>>l;

    memset(vis,0,sizeof(vis));
    
    int arr[k];
    solve(0,arr,0);  

    return 0;
}