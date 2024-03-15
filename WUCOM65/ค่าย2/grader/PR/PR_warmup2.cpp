#include<bits/stdc++.h>
using namespace std;
#define MOD 1e9+1

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long int n; cin>>n;
    cout << ((n%1000000007) * (n%1000000007))%1000000007;

    return 0;
}