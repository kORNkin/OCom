#include<bits/stdc++.h>
using namespace std;
struct Time{
    int amt,t,k;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q,t; cin>>q>>t;
    vector<Time> arr;
    while(t--){
        int amt,s,e; cin>>amt>>s>>e;
        arr.push_back({amt,s,1});
        arr.push_back({amt,e+1,-1});
    }
    sort(arr.begin(),arr.end(),[&](Time a,Time b){
        if(a.t == b.t) return a.k < b.k;
        return a.t < b.t;
    });
    while(q--){
        int n,cnt=0; cin>>n;
        for(auto x:arr){
            if(x.t > n) break;
            cnt+=x.amt*x.k;    
        }
        cout << cnt << '\n';
    }

    return 0;
}