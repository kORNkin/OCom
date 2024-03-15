#include<bits/stdc++.h>
using namespace std;
long long int fac(int n){
    long long int tmp=1;
    for(int i=2;i<=n;i++)
        tmp*=i;
    return tmp;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--){
        int n,r; cin>>n>>r;
        cout << fac(n)/fac(n-r)/fac(r) << '\n';
    }

    return 0;
}