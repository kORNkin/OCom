#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    int arr[n];
    for(auto &x:arr) cin>>x;
    sort(arr,arr+n);
    if(n%2==0){
        cout << fixed << setprecision(1) << (double)(arr[n/2]+arr[n/2-1])/2;
    }else cout << fixed << setprecision(1) << (double)arr[n/2];

    return 0;
}
