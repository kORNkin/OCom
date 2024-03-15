#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    int mx=0,mxx=0;
    for(int i=1;i<=n;i++){
        int a,b; cin>>a>>b;
        if(mx<a*b){
            mx=a*b;
            mxx=i;
        }
    } cout << mxx;

    return 0;
}