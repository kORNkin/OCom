#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define N 50001
vector<bool> isP(N,1);
int co=0;
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void Prime(){
    isP[0]=0;
    isP[1]=0;
    for(ll j=4;j<N;j+=2){
        isP[j]=0;
    }
    for(ll i=3;i<N;i+=2){
        if(isP[i]){
            for(ll j=i+i;j<N;j+=i){
                isP[j]=0;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    Prime();
    ll n,a,b;cin>>n;
    cin>>a;
    for(ll i=1;i<n;i++){
        cin>>b;
        a = a*b/gcd(a,b);
    }
    for(ll i=2;i<=a;i++){
        if(a==1){
            break;
        }
        if(isP[i]){
            while(a%i==0){
                co++;
                a/=i;
            }
        }
    }
    cout << co;

    return 0;
}