#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    int arr[n],med=0,sum=0;
    for(auto &x:arr)
    {
        cin>>x;
        med+=x;
    } 
    med/=n;
    for(auto &x:arr){
        if(x>med) sum+= x-med;
    }
    cout << sum;


    return 0;
}