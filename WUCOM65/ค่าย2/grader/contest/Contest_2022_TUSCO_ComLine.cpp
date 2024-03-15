#include<bits/stdc++.h>
using namespace std;
long long int arr[10001];
long long int tar,n,mn=LLONG_MAX;
bool vis[10001];

void solve(int i,long long int sum,int d){   
    if(d==tar){
        mn=min(sum,mn);
        return;
    }
    if(i>=n) return;

    for(int j=i;j<n-1;j++){
        if(vis[j]) continue;
        vis[j]=1;
        vis[j+1]=1;

        solve(j+2,sum+arr[j+1]-arr[j],d+1);

        vis[j]=0;
        vis[j+1]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>tar>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(vis,0,n);

    solve(0,0,0);
    cout << mn;

    return 0;
}