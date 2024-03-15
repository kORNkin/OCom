#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;cin>>T;
    while(T--){
        int n; cin>>n;
        vector<pair<string , pair<int,int>>> arr; 
        while(n--){
            char c; cin>>c;
            int x;
            if(c=='a') {
                string s; int a,b;
                cin>>s>>a>>b;
                arr.push_back({s,{a,b}});
            }else if(c=='b'){
                cout << arr.size() << ' ';
            }else if(c=='c'){
                for(auto e:arr){
                    cout << e.first << ' ' << e.second.first << ' ' << e.second.second << ' ';
                } 
            }else if(c=='d'){
                sort(arr.begin(),arr.end(), [&](pair<string , pair<int,int>> a, pair<string , pair<int,int>> b){
                    if(a.second.first == b.second.first) return a.second.second < b.second.second;
                    return a.second.first<b.second.first;
                });
            }
        } cout << '\n';
    }

    return 0;
}