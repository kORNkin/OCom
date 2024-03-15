#include<bits/stdc++.h>
using namespace std;

long long n, a[100001], b[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    long long mx = -1e18;
    for(int i = 0; i < n; i++){
        mx = max(mx, abs(a[i] - b[i]));
    }

    cout << mx;

    return 0;
}