#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int arr[n];
    for(auto &x:arr) cin>>x;
    cout << *max_element(arr,arr+n);

    return 0;
}