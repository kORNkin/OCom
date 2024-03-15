#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char c; cin>>c;
    int n; cin>>n;
    for(int i=-n;i<=n;i++){
        for(int j=-n;j<=n;j++){
            if(i==j || i+j == 0 || i==0 || j==0) cout << '+';
            else if(-abs(j) <= i-n-1 || abs(j) >= i+n+1) cout << '.';
            else cout << c;
        } cout << '\n';
    }
    
    return 0;
}