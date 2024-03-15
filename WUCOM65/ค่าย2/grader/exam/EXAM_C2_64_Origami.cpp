#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    int l,r; cin>>l>>r;
    string s="v";
    for(int i=1;i<n;i++){
        string tmp = s;
        s.push_back('v');
        for(int j=tmp.size()-1;j>=0;j--){
            if(tmp[j]=='v') s.push_back('^');
            else s.push_back('v');
        }
    }
    for(int i=l;i<=r;i++)
        cout << s[i];

    return 0;
}