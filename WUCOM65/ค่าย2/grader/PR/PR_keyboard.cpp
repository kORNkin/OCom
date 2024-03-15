#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin>>s;
    bool hm=0;
    string arr;
    string tmp;
    for(auto c:s){
        if(c=='['){
            hm=1;
            continue;
        }else if(c==']'){
            arr = tmp + arr;
            tmp.clear();
            hm=0;
            continue;
        }
        if(hm){
            tmp.push_back(c);
        }else arr.push_back(c);
    }
    cout << arr;
    
    return 0;
}