#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int K; cin>>K;
    map<int,vector<int>> plat;
    while(K--){
        char c; cin>>c;
        int a,b; cin>>a>>b;
        if(c=='N'){
            plat[b].push_back(a);
        }else {
            for(auto e:plat[a]){
                plat[b].push_back(e);
            }
            plat.erase(a);
        }         
    }
    for(auto i:plat){
        for(auto j:i.second){
            cout << j << '\n';
        }
    }
    

    return 0;
}

