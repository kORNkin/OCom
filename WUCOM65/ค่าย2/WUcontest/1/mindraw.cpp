#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long int n,sum = 0; cin>>n;
    vector<int> arr;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        if(x > 0) arr.push_back(x);
        else if(!arr.empty()){
            sort(arr.begin(),arr.end(),greater<int>());
            sum += arr.back();
            arr.pop_back();
        }
    } cout << sum;

    return 0;
}