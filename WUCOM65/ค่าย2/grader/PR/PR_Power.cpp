#include<bits/stdc++.h>
using namespace std;

int poww(int a, int b){
    if(b == 0) return 1;

    int x = poww(a, b / 2) % 1000;
    if(b&1) return (x * x * (a% 1000))% 1000;
    return (x * x)% 1000;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        cout << poww(n,m) << '\n';
    }

    return 0;
}