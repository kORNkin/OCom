#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n; cin>>n;
    while(true){
        if(n==1){
            cout<<1; break;
        } cout<<n<<" ";
        if(n%2) n= n*3+1;
        else n/=2;
    }

    return 0;
}