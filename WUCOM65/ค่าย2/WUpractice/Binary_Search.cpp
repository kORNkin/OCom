#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100001];

bool bs(int l,int r,int x){
    if(l==r){
        if(arr[l]!=x){
            return 0;
        } return 1;
    }
    int m  = (l+r)>>1;

    if(x <= arr[m]) return bs(l,m,x);
    else return bs(m+1,r,x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin>>n>>T;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    while(T--){
        int x; cin>>x;
        if(bs(0,n-1,x))
            cout << "Y\n";
        else cout << "N\n";
    }

    return 0; 
}