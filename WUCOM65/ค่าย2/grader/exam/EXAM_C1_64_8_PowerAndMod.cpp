#include<bits/stdc++.h>
using namespace std;
long long int solve(int a,int b,int m){
    
    if(b==0) return 1;
    if(b==1) return a%m;
    
    long long int n = solve(a,floor(b/2),m) %m;
    if(b%2==0) return (n*n)%m;
    return ((n*n)%m *(a%m))%m ;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while(T--){
        long long int a,b,m; cin>>a>>b>>m;
        cout << solve(a,b,m) << '\n';
    }

    return 0;
}