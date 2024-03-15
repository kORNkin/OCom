#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<9;i++){
        sum+= (s[i]-'0') * (10-i);
    }
    int x = 11-sum%11;
    s += x+'0';
    cout << s;

    return 0;
}
