#include <bits/stdc++.h>
using namespace std;

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    long long k,sum=0;cin>>k;
    while(k--){
        int f,b,p; cin>>f>>b>>p;
        long long x=f*b-p;
        sum+=x; cout << x << "\n";
    }
    cout << sum;

    return 0;
}