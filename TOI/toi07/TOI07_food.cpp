/*TASK:
LANG: C++
AUTHOR: Supphakon Yimi
CENTER: WU
*/
#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
int n,m;
bool ct[10],vis[10]; 
string res;
void solve(int d)
{
    if(d==n) 
    {
        cout << res << endll;
    }
    else 
    {
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                res+=' ';
                res+=i+'0';
                vis[i]=1;
                solve(d+1);
                vis[i]=0;
                res.pop_back();
                res.pop_back();
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    memset(ct,0,sizeof(ct));
    memset(vis,0,sizeof(ct));
    for(int i=0;i<m;i++)
    {
        int x; cin >> x;
        ct[x]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!ct[i])
        {
            res+=i+'0';
            vis[i]=1;
            solve(1);
            vis[i]=0;
            res.pop_back();
        }
    }
    return 0;
}