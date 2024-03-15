#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,b; cin>>n>>b;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,greater<int>());
    int mx=0;
    int k=0;
    for(int i=0;i<n;i++){
        while(arr[i]%(b-k-(n-1-i)) ==0){
            k++;
        }
        mx = max(arr[i]/(b-k-(n-1-i)),mx);
        b-= b-k-(n-1-i);
        k=0;
    }
    cout << mx;

    return 0;
}
