#include<bits/stdc++.h>
using namespace std;

long long n, x[100001], y[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }   

    sort(x, x + n), sort(y, y+ n);
    cout << x[n / 2] << ' ' << y[n / 2];


    return 0;
}
