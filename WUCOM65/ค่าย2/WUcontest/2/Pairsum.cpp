#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,k; cin>>n>>k;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n,greater<int>());
    int i=0,j=0,cnt=0;
    while(j<n && i<n){
        if(a[i]+b[j] > k){
            cnt++;
            j++;
            i++;
        }else {
            i++;
        }
    }
    cout << cnt;

    return 0;
}