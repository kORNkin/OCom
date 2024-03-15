#include<bits/stdc++.h>
using namespace std;
int n,k;
bool vis[10001];
int arr[10001];
int cnt=0;
void solve(int idx,int sum){
    if(sum > k || arr[idx] > k) return;
    if(sum==k) {
        cnt++;
        return;
    }

    for(int i=idx+1;i<n;i++){
        solve(i,sum+arr[i]);
    }
}

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(0);

    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>k;

    memset(vis,0,sizeof(vis));
    solve(-1,0);

    cout << cnt;

    return 0;
}