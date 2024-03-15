#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    long long n; cin>>n;
    deque<long long> L(5,1);
    L[0]=0;

    for(int i = 5; i <= n; i++){
        L.push_back(L[1] + L[2] + L[3] + L[4]);
        *L.rbegin() %= mod;
        cout << i << " : " << L.back() << '\n';
        L.pop_front();
    }
   
    cout << L.back();

    return 0;
}