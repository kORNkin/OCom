#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
typedef long long ll;
typedef double db;
bool t[50005][100];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,mx=0;
    cin >> n;
    while(n--)
    {
        int p,q,r;
        cin >> p >> q >> r;
        if(mx <= p) mx = p;
        
        for(int i=q-1;i<q+r-1;i++)
            t[p-1][i] = 1;
        
    }
    for(int i=0;i<mx;i++)
    {
        for(int j=0;j<70;j++)
        {
            if(t[i][j]==1)
                cout << 'x';
            else cout << 'o';
        }
        cout << endll;
    }
    return 0;
}