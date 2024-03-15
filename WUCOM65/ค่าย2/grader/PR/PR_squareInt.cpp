#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    double n; cin>>n;
    double m =floor(sqrt(n));
    m=(m != sqrt(n))?m:m-1;
    cout << fixed << setprecision(0) << m;

    return 0;
}