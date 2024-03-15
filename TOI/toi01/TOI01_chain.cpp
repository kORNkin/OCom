#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
typedef long long ll;
typedef double db;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int len,t;
    cin >> len >> t;
    string st[t];
    for(int i=0;i<t;i++)
        cin >> st[i];
    for(int i=0;i<t-1;i++)
    {
        int co=0;
        for(int j=0;j<len;j++)
        {
            if(st[i][j]!=st[i+1][j]) co++;
        }
        if(co>2)
        {
            cout << st[i];
            return 0;
        }
    }  
    cout << st[t-1];    

    return 0;

}