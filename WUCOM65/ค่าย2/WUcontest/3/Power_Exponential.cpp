#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int n,k;
long long int poww(int n,int k){
    if(k==0) return 1;
    if(k==1) return n;

    long long x = poww(n,floor(k/2))%mod;
    if(k%2==0) return x%mod * x%mod;
    else return x%mod * x%mod * n%mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long int sum=0;
    int T; cin>>T;
    while(T--){
        cin>>n>>k;
        sum+=poww(n,k)%mod;
        sum%=mod;
    }
    cout << sum;

    return 0;
}