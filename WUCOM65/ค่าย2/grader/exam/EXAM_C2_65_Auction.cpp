#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    int n,m,a;
    cin>>n>>m>>a;
    short int cnt[n+1];
    for(int i=1;i<=n;i++)
        cin>>cnt[i];
    vector<pair<short int,int>> mem[m+1];
    set<pair<short int,int>,greater<pair<short int,int>>> arr[n+1];
    while(a--){
        char c; cin>>c;
        int u,i,v;
        if(c=='B'){
            cin>>u>>i>>v;
            int vv=0;
            for(auto j=mem[u].begin();j!=mem[u].end();j++){
                if((*j).second == i){
                    vv=(*j).first;
                    mem[u].erase(j);
                    break;
                }
            }
            if(arr[i].find({vv,u}) != arr[i].end()){
                arr[i].erase({vv,u});
            }
            mem[u].push_back({v,i});
            arr[i].insert({v,u});
        }else {
            cin>>u>>i;
            int vv=0;
            for(auto j=mem[u].begin();j!=mem[u].end();j++){
                if((*j).second == i){
                    vv=(*j).first;
                    mem[u].erase(j);
                    break;
                }
            }
            if(arr[i].find({vv,u}) != arr[i].end()){
                arr[i].erase({vv,u});
            }
        }
    } 

    vector<short int> ans[m+1];
    for(int i=1;i<=n;i++){
        if(!cnt[i]) continue;
        for(auto e:arr[i]){
            if(cnt[i]){
                ans[e.second].push_back(i);
                cnt[i]--;
            }else break;
        }
    }
    for(int i=1;i<=m;i++){
        if(!ans[i].size()){
            cout << "NONE\n"; continue;
        }
        for(auto e:ans[i])
            cout << e << " ";
        cout << '\n';
    }

    return 0;
}