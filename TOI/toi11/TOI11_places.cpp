/*TASK:
LANG: C++
AUTHOR: Supphakon Yimi
CENTER: WU
*/
#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
#define mod 1000000007
#define st first
#define nd second
#define pr pair<int,int>
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

int n,m;
ll ans = 0;

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b)
{
    return get<2>(a) > get<2>(b); 
}

int find(vector<int> &par,int x)
{
    if(par[x] != x)
        par[x] = find(par,par[x]);
    return par[x];
}

void union_set(vector<int> &par,vector<int> &rank ,int a, int b)
{
    int par_a = find(par,a);
    int par_b = find(par,b);


    if(rank[par_a] > rank[par_b])
        par[par_b] = par_a;
    else 
    {
        par[par_a] = par_b;

        if(rank[par_a] == rank[par_b])
            rank[par_b] ++ ;
    }
}

void kruskal(vector<tuple<int,int,int>> &allE)
{
    vector<int> par(n+5);
    vector<int> rank(n+5);

    for(int i=1;i<=n;i++)
    {
        par[i] = i;
        rank[i] = 0;
    }

    sort(allE.begin(),allE.end(),cmp);

    for(auto e:allE)
    {
        int a = get<0>(e);
        int b = get<1>(e);
        int w = get<2>(e);

        if(find(par,a) != find(par,b))
        {
            ans+=w;

            union_set(par,rank,a,b);
        }
    }

    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    vector<tuple<int,int,int>> allE;
    while(m--)
    {
        int u,v,w;
        cin >> u >> v >> w;
        allE.emplace_back(make_tuple(u,v,w-1));
    }
    khan(allE);
    cout << ans;
    return 0;

}