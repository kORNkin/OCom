#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    int n,sum=0;cin>>n;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            sum+=gcd(i,j);
        }
    }
    cout << sum;

    return 0;
}