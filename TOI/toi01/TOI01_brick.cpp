#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
typedef long long ll;
typedef double db;

int main()
{

    int n, m;
    cin >> n >> m;
    string ch[n];
    for (int i = 0; i < n; i++)
        cin >> ch[i];

    int x[m];
    for (int j = 0; j < m; j++)
        cin >> x[j];
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < x[i]; k++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ch[j][i] == 'O' || ch[j][i] == '#')
                {
                    if(j!=0)
                        ch[j-1][i] = '#';
                    j=n;
                }else if(j==n-1 && ch[j][i]=='.')
                {
                    ch[j][i] = '#';
                    j=n;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << ch[i];
        cout << endll;
    }

    return 0;
}
