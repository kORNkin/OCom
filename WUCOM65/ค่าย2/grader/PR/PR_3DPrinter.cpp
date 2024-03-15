#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    double n; cin>>n;
    n = ceil(log2(n));
    cout << n+1;

    return 0;
}