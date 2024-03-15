#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int>> v;
bool vis[11];
int Mx=0;
void solve(int i,int k,int arr[]){
    if(k==n+1){
        for(int l=1;l<=n;l++){
            cout << arr[l] << " ";
        } cout << '\n';
        int sum=0;
        for(int l=0;l<v.size();l++){
            int mx=0,mn=1e9;
            for(int h=v[l].first;h<=v[l].second;h++){
                mx = max(arr[h],mx);
                mn = min(arr[h],mn);
            }
            sum+=mx-mn;
        } Mx = max(sum,Mx);
        return;
    }
    for(int j=1;j<=n;j++){
        if(!vis[j]){
            vis[j]=1;
            arr[k]=j;
            solve(i+1,k+1,arr);
            vis[j]=0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    cin>>n>>m;
    while(m--){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }
    memset(vis,0,sizeof(vis));
    int arr[10];
    solve(0,1,arr);
    cout << Mx;
    
    return 0;
}