#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>

 
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

const int MOD = 1e9 + 7;
 
using namespace std;
 
int main() {
    fast;
    int t;
    cin>>t;
    while(t--){
        string s,tmp;  
        cin>>s;
        tmp = s;
        int sum=0;
        for(int i=0;i<12;i++){
            sum+=(13-i)*(s[i]-'0');
        }
        sum%=11;
        sum= (11-sum)%10;
        tmp[tmp.size()-1] = sum+'0';

        if(tmp==s) cout << "Y\n";
        else cout << "N\n";
    }
}