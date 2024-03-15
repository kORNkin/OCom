#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    int arr[n],qs=0;
    for(auto &x:arr) 
    {
        cin>>x;
        qs+=x;
    }

    int t=0;
    n=n-1;
    cout << qs << '\n';
    while(t!=n){
        if(arr[t] >= arr[n]){ 
            qs-=arr[t];
            t++; cout << qs << '\n';
        }else {
            qs-=arr[n];
            n--; cout << qs << '\n';
        }
    } cout << t+1;

    return 0;
}