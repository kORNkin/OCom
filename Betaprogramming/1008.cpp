#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,l,h,r,L=256,R=0;
    cin>>n;
    int mem[256];
    memset(mem,0,sizeof(mem));
    while(n--){
        cin>>l>>h>>r;
        L = min(L,l);
        R = max(R,r);
        for(int i=l;i<r;i++){
            mem[i]=max(mem[i],h);
        }
    }
    for(int i=L;i<=R;i++){
        if(mem[i]!=mem[i-1])
            cout << i << " " << mem[i] << " ";
    }
    return 0;
}