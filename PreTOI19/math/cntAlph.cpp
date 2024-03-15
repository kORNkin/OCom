#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin,s);

    int cnt[26];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<s.size();i++)
        cnt[toupper(s[i])-'A']++;
    for(int i=0;i<26;i++)
        if(cnt[i]) 
            cout << char('A'+i) << " = " << cnt[i] << '\n';
    return 0;
}