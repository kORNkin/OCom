#include <bits/stdc++.h>

using namespace std;

bool isInt(string s){
    int n=s.length();
    bool ch=0;
    for(int i=0;i<n;i++){
        if(ch){
            if(s[i]!='0')
                return 0;
            continue;
        }
        if(s[i]=='.')
            ch=1;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s; cin>>s;
        if(isInt(s))
            cout << "OK\n";
        else cout << "NOT INTEGER\n";
    }
    
    return 0;
}
