#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    vector<pair<int,bool>> arr;
    while(n--){
        int a,b; cin>>a>>b;
        arr.push_back({a,1});
        arr.push_back({b,0});
    }
    sort(arr.begin(),arr.end(), [&](pair<int,bool> a,pair<int,bool> b){
        if(a.first == b.first) return a.second<b.second;
        return a.first < b.first;
    });

    int co=0,mx=0;
    for(auto e:arr){
        if(e.second) co++;
        else co--;

        mx=max(mx,co);
    } cout << mx;

    return 0;
}