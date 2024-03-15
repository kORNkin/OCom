#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin>>T;
    while(T--){
        double n; cin>>n;
        if(n-floor(n) < 1e-9){
            cout << "OK\n";
        }else cout << "NOT INTEGER\n";
    }

    return 0;
}