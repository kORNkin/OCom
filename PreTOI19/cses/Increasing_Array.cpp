#include<bits/stdc++.h>
using namespace std;
#define cin(a) for(auto &_x:(a)) cin>>_x;

int main()
{
    ios_base::sync_with_stdio(0);

    long long n,move=0; cin>>n;
    long long arr[n];
    cin(arr);
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            move+= arr[i-1]-arr[i];
            arr[i] = arr[i-1];
        }
    } cout << move;

    return 0;
}