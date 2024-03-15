#include <bits/stdc++.h>
using namespace std;
long long int n,k,cnt=0;
void solve(int i,int kk,bool ch){
    if(kk>k) return;
    if(i==n){
        cnt++;
        return;
    }
    if(!ch) solve(i+1,kk+1,1);
    solve(i+1,kk,0);
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    cin>>n>>k;
    solve(0,0,0);
    cout << cnt;
    
    return 0;
}