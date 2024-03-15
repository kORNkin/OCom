#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q; cin>>q;
    list<string> l;
    auto it = l.begin();

    while(q--){
        char op; cin>>op;
        if(op=='l'){
            if(l.empty() || it==l.begin()) continue;
            it--;
        }else if(op=='r'){
            if(l.empty() || it== l.end()) continue;
            it++;
        }else if(op=='i'){
            string s; cin>>s;
            l.insert(it,s);
        }else if(op=='b'){
            if(l.empty() || it==l.begin()) continue;  
            it = l.erase(--it);
        }else if(op=='d'){
            if(l.empty() || it== l.end()) continue;
            it = l.erase(it);
        }
    }
    for(auto s:l){
        cout << s << ' ';
    }

    return 0;
}