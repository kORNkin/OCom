#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int mem[256];
    memset(mem,0,sizeof(mem));

    int n; cin>>n;
    int L=256,R=0;
    while(n--){
        int l,h,r; cin>>l>>h>>r;
        for(int i=l;i<r;i++)
            mem[i]=max(mem[i],h);
        L = min(L,l);
        R = max(R,r);
    }
    for(int i=L;i<=R;i++){
        if(mem[i]!=mem[i-1]){
            cout << i << " " << mem[i] << " ";
        }
    } 

    return 0;
}