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
int n,m,k;

bool cmp(string a,string b)
{
    for(int i=0;i<b.length();i++)
        if(tolower(a[i]) != tolower(b[i])) return 0;
    return 1;
}

bool solve(string s[],string t[],int j,int i,int l,bool vis[])
{
    
    pair<int,int> li[] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    for(int z=0;z<8;z++)
    {
        string tmp;
        int co=0;
        int a=i,b=l;
        while(a>=0 && b>=0 && a<n && b<m)
        {
            if(co == t[j].length()) break;
            tmp+=s[a][b];
            a+=li[z].first;
            b+=li[z].second;
            
            co++;
        }
        //cout << tmp << endll;
        if(cmp(tmp,t[j]))
        {
            vis[j]=1;
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >>m;
    string s[n];
    for(int i=0;i<n;i++)
        cin >> s[i];
    cin >> k;
    string t[k];
    for(int i=0;i<k;i++)
        cin >> t[i];
    bool vis[k];
    memset(vis,0,sizeof(vis));
    vector<pair<int,int>> ans(k);
    for(int i=0;i<n;i++)
    {
        for(int l=0;l<s[i].length();l++)
        {
            for(int j=0;j<k;j++)
            {
                if(!vis[j] && tolower(t[j][0]) == tolower(s[i][l]))
                {
                    if(solve(s,t,j,i,l,vis))
                        ans[j]= {i,l};
                }
            }
        }
    }
    for(auto i:ans)
    {
        cout << i.first << " " << i.second << endll;
    }

    return 0;

}