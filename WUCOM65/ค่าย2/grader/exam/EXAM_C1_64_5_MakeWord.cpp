#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int poww(int a,int b){
    if(b==0) return 1;
    if(b==1) return a;
     
    long long x = poww(a,b/2)%mod;
    if(b%2==0) return (x*x)%mod;
    else return ((x*x)%mod) * (a%mod);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin>>s;
    long long int sum=s[s.size()-1]-'a', k=1;
    for(int i=s.size()-2;i>=0;i--){
        sum+=((((s[i]-'a')+1))%mod)*poww(26,k);
        sum%=mod; 
        k++;
    } cout << sum%mod;
    
    return 0;
}