#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    while(m--){
        int a,b; cin>>a>>b;
        swap(arr[a-1],arr[b-1]);
    }
    for(int i=0;i<n;i++) cout<<arr[i]<< " ";

    return 0;
}