#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    string s; cin>>s;
    string ans;
    int cnt=0,o=0;
    for(int i=0;i<s.size();i++)
        if(s[i]=='1') cnt++;
    for(int i=0;i<s.size();i++){
        ans.push_back(s[i]);
        if(s[i]=='1') o++;
        int k=0;
        bool ch=0;
        if( (o!=0 &&cnt%o != 0) || ((ans.size()-o !=0)&&(s.size()-cnt)%(ans.size()-o)!=0)) continue;
        for(int j=ans.size();j<s.size();j++){
            if(ans[k] != s[j]){
                ch = 1;
                break;
            }
            k++;
            k%=ans.size();
        }
        if(!ch && k==0){
            cout << ans.size();
            return 0;
        }
    }

    return 0;
}