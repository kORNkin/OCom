#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin>>n;
    int arr[n];
    for(auto &x:arr) cin>>x;
    int x=arr[0],sum=0;
    for(int i=1;i<n;i++){
        if(x>=arr[i]){
            x=arr[i];
        }else {
            sum+=arr[i]-x;
            x=arr[i];
        }
    }
    cout << sum;

    return 0;
}
