#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,x; cin>>n;
    long long sum=0;
    for(int i=0;i<n;i++) cin>>x, sum+=x;
    if(sum%3==0) cout << "Y\n";
    else cout << "N\n";

    return 0;
}
/*
3
4
6
1
*/