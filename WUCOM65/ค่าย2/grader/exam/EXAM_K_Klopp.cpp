#include<bits/stdc++.h>
using namespace std;
int co=0,mx=0;
void solve(float n){
    mx= max(mx,(int)n);
    co++;
    if(n == 1) return;
    if((int)n%2==0){
        solve(floor(sqrt(n)));
    }else {
        solve(floor(pow(sqrt(n),3)));
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    float n; cin>>n;
    solve(n);
    cout << mx << " " << co;

    return 0;
}