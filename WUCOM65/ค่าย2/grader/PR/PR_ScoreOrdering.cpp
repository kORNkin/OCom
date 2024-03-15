#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,k; cin>>n>>k;

    vector<pair<int,string>> arr;
    while(n--){
        string s; int x; cin>>s>>x;
        arr.emplace_back(x,s);
    }
    sort(arr.begin(),arr.end(),[&](pair<int,string> a,pair<int,string> b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    for(int i=0;i<k;i++)
        cout << arr[i].second << ' '<< arr[i].first << '\n';
    

    return 0;
}