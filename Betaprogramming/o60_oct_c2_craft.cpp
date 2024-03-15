#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N,W;
ll arr[30];
bool ch=0;
ll solve(ll w,int idx){
    if(ch) return -1;
    if(w < 1) { ch=1; return -1; }
    if(idx < 1) return w;
    
    ll ww = w*2-arr[idx]+1;
    if(ww&1) return solve(ww/2,idx-1)+solve((ww+1)/2,idx-1); 
    else return solve(ww/2,idx-1)*2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>W;
    for(int i=1;i<N;i++) cin>>arr[i];

    ll w = solve(W,N-1);
    cout << (ch ? -1:w);

    return 0;
}