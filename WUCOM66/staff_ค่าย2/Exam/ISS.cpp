/*
Problem: IncreasingSequence
Author: kornkin
Algor: State space search
*/
#include<bits/stdc++.h>
using namespace std;

int n, cnt;

void solve(int k, int d){
    if(k == 0) {
        cnt++;
        return;
    }
    for(int i = d; i > 0; i--){
        if(k - i < 0) return;
        solve(k - i, min(k-i, i));
    }
}

int main(){
    ios_base::sync_with_stdio(0);

    cin >> n;
    solve(n, n);
    cout << cnt;
    
    return 0;
}