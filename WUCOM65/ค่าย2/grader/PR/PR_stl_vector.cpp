#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> v; 
        while(n--){
            char c; cin>>c;
            int x;
            if(c=='a') {
                cin>>x;
                v.push_back(x);
            }else if(c=='b'){
                sort(v.begin(),v.end());
            }else if(c=='c'){
                reverse(v.begin(),v.end());
            }else if(c=='d'){
                cout << v.size() << " ";
            }else if(c=='e'){
                for(auto e:v) cout << e << ' ';
            }else if(c=='f'){
                sort(v.begin(),v.end(),greater<int>());
            }
        } cout << '\n';
    }

    return 0;
}