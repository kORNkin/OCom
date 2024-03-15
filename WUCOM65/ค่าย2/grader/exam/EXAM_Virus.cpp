#include<bits/stdc++.h>
using namespace std;
int cal(string key){
    int tmp = 0;
    for(auto c:key){
        tmp+= c-'0';
    }
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string key; 
    int l; cin>>l>>key;
    
    int k = cal(key);

    int T; cin>>T;
    while(T--){
        string s; cin>>s;
        for(auto c:s){
            cout << (char)(((c-'A'+k)%26)+'A');
        }
        cout << '\n';
    }


    return 0;
}