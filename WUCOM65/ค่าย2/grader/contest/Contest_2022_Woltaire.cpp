#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t;
    int cnt=0;
    set<string> user;
    map<string,vector<string>> admin;
    while(t--){
        string s,a,b; cin>>s>>a;
        getline(cin,b);
        if(s!="send" || b=="\0") cnt++;
        else {
            user.insert(a);
            admin[a].push_back(b);
        }
    }
    if(cnt) cout << "=== admin log ===\n";
    while(cnt--) cout << "The format is not supported\n"; 
    for(auto s:user){
        cout << "=== " << s << " ===\n";
        for(auto txt:admin[s]){
            cout << "Woltaire:" << txt << '\n';
        }
    }

    return 0;
}