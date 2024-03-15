#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int arr[n][5];
    int a=0,b=100001,c;
    for(int i=0;i<n;i++){
        int mx=0,mn=100001;
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
            mx=max(mx,arr[i][j]);
            mn=min(mn,arr[i][j]);
        }
        a=max(a,mx-mn);
        b=min(b,mx-mn);
    }
    cout << a << " " << b << " " << a-b;

    return 0;
}