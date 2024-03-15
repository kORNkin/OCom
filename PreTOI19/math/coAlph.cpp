#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int cnt[256];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<s.size();i++)
        cnt[toupper(s[i])]++;
    for(int i='A';i<='Z';i++)
        if(cnt[i])
            for(int j=i+1;j<='Z';j++)
                if(cnt[j]) 
                    cout << char(i) << char(j) <<'\n';                       

    return 0;
}