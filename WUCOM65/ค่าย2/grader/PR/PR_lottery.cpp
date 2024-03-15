#include<bits/stdc++.h>
using namespace std;
int n,arr[10001];
bool vis[10001];
vector<int> ans;
void solve(int idx,int k){
    if(k==6){
        for(int i=0;i<k;i++) cout << ans[i] << ' ';
        cout << '\n';
        return ;
    }

    for(int i=idx;i<n;i++){
        if(!vis[i]){
            vis[i]=1;
            ans.push_back(arr[i]);
            solve(i+1,k+1);
            vis[i]=0;
            ans.pop_back();
        }
    }
}

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(0);

    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    memset(vis,0,sizeof(vis));
    solve(0,0);

    return 0;
}