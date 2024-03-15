#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    int mn=100001,mx=0;
    while(n--){
        int tmp; cin>>tmp;
        mx=max(mx,tmp);
        mn=min(mn,tmp);
    }
    cout << mx*2+mn;

    return 0;
}