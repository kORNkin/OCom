#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(!b) return a;
    return gcd(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,mx=1;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<i;j++)
            mx=max(mx,gcd(arr[i],arr[j]));
    }
    cout << mx;

    return 0;
}