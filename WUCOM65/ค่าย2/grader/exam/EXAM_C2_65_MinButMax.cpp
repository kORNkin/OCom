#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    int arr[n+1]; 
    double x[n+1]; x[0] = 0;
    for(int i=1;i<=n;i++) cin >> arr[i];
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n;i++)
        x[i] = x[i-1]+arr[i]; 
    for(int i=1;i<=n;i++)
        x[i] /= i; 

    for(int i=1;i<=n;i++){
        cout << x[i] << ' ';
    } cout << '\n';

    int q; cin>>q;
    while(q--){
        double k; cin>>k;
        auto it = lower_bound(x+1,x+1+n,k);
        cout << (it-x-1) << '\n';
    }

    return 0;
}
/*
5
5 3 1 2 4
5
1
2
3
4
5
*/
