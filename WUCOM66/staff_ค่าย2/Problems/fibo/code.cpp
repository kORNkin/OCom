/*
Problem: 
Algor: Math
Author: kornkin
*/
#include<bits/stdc++.h>
using namespace std;

int n, sum;
int fi[10000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    fi[1] = fi[2] = 1;

    for(int i = 3; i <= n + 2; i++){
        fi[i] = fi[i - 1] + fi[i - 2];
    }

    for(int i = 1; i <= n; i++) sum += fi[i];

    cout << sum << ' ' << fi[n + 2] - 1;

    return 0;
}