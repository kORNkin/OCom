#include<bits/stdc++.h>
using namespace std;
int arr[20001];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<n;i++) cin>>arr[i];

    int x=0,y,mx=-1e9,sum=0;
    for(int i=1;i<n;i++){
        sum+=arr[i];
        if(sum < arr[i]){
            sum = arr[i];
            x=i;
        }
        if(mx <= sum) {
            mx = sum;
            y=i;
        }
    }
    if(mx > 0) cout << x << ' ' << y+1;
    else cout << "no";

    return 0;
}
