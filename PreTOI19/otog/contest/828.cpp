#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(nullptr); cout.tie(nullptr);

    /*long long n,ch=0,sum=0; cin>>n;
    long long arr[n],tmp[n];
    for(long long &x:arr) cin>>x;
    for(int i=0;i<n;i++) tmp[i]=arr[i];
    for(int i=1;i<n-1;i++){
        long long x = (long long)floor((tmp[i-1]+tmp[i]+tmp[i+1])/3);
        if(arr[i]<x){
            arr[i]=x; ch++;
        }
    }
    for(long long &x:arr) sum+=x;
    cout << ch << " " << sum;*/

    ll n,tmp; cin>>n;
    ll ch=0,sum=0;
    ll a,b,c; cin>>a>>b; n-=2;
    sum+=a;
    while(n--){
        cin>>c;
        ll x = (ll) floor((a+b+c)/3);
        if(b<x){
            sum+=x;
            ch++;
        }else sum+=b;
        tmp = b;
        b = c;
        a = tmp;
    }
    sum+=c;
    cout << ch << " " << sum;

    return 0;
}