#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long t,n; cin>>t>>n;
    long long mn=0;
    if(n%15 >= 9) {
        mn += ceil(n/15.0)*300;
        n=0;
    }else{
        mn += floor(n/15.0)*300;
        n-=floor(n/15.0)*15;
    } 
    if(n==8) mn+=280;
    else if(n==7) mn+=230;
    else if(n==6) mn+=200;
    else if(n==5 || n==4) mn+=150;
    else if(n==3) mn+=130;
    else if(n==2) mn+=80;
    else if(n==1) mn+=50;

    while(t--){
        long long x; cin>>x;
        if(x < mn) cout << "-1\n";
        else cout << x-mn << '\n';
    }

    return 0;
}