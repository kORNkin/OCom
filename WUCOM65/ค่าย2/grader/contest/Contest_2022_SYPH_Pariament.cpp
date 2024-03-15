#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin>>n>>m;
    int mem[n+1]; memset(mem,0,sizeof(mem));
    mem[0]=1;
    int arr[m];
    for(auto &x:arr) 
        cin>>x;
    for(int i=1;i<=n;i++){
        for(auto x:arr){
            if(i-x > -1) mem[i]+=mem[i-x];
        }
    } cout << mem[n];

    return 0;
}