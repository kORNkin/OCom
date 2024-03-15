#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin>>s;
    int mx=1,tmp=1;
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]) tmp++;
        else {
            mx = max(mx,tmp);
            tmp=1;
        }
    }
    mx = max(mx,tmp);
    cout << mx;

    return 0;
}