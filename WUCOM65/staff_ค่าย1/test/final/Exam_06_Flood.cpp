#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin>>n;
    int arr[n];
    for(auto &x:arr) cin>>x;

    for(int i=0;i<n-1;i++){
        if(arr[i] < arr[i+1])
            cout<<arr[i]<<' ';
        else {
            int mx=i+1;
            for(int k=i+1;k<n;k++){
                if(arr[mx]<arr[k])
                    mx=k;
                if(arr[mx] >= arr[i])
                    break;
            }
            for(int j=i;j<mx;j++)
                cout << min(arr[mx],arr[i]) << ' ';
            i=mx-1;
        }
    }

    return 0;
}
