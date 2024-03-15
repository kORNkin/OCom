#include<bits/stdc++.h> 
using namespace std;
long long int n,p,mod;
long long int poww(long long int n,long long int p){
    if(p==0) return 1;
    if(p==1) return n;

    long long int x = poww(n,p/2)%mod;
    if(p%2==0) return (x%mod*x%mod)%mod;
    else return (x%mod*x%mod*n%mod)%mod;
}
int main(){

    int t; cin>>t;
    while(t--){
        int d;
        cin>>n>>p>>d;
        int x=d;
        mod = 1;
        while(d--)
            mod*=10;
        n= poww(n,p);
        cout<<setfill('0')<< setw(x)<<n<<'\n';
    }

    return 0;
}