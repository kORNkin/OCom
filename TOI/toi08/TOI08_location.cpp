/*TASK:
LANG: C++
AUTHOR: Supphakon Yimi
CENTER: WU
*/
#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
#define mod 1000000007
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
int sum[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> sum[i][j];
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }

    int mx=0;
    for(int i=k;i<=n;i++)
    {
        for(int j=k;j<=m;j++)
        {
            mx = max(mx,sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k]);
        }
    }
    cout << mx;
    
    return 0;

}