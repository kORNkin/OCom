#include <bits/stdc++.h>
using namespace std;
void solve(int n, char a,char b,char c){
    if(!n) return;
    solve(n-1,a,c,b);
    cout << a << " --> " << c << '\n';
    solve(n-1,b,a,c);
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    int n; cin>>n;
    solve(n,'A','B','C');

    return 0;
}