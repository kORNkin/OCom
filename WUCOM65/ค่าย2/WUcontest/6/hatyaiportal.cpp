#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int dis[10001];
pair<int,int> g[10001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++) cin>>g[i].first>>g[i].second, dis[i]=1e9;

    long long sum=0;
    for(int i=0;i<n-1;i++){
        int mn=1e9;
        int imn;
        for(int j=i+1;j<n;j++){
            int d = abs(g[i].first-g[j].first)+abs(g[i].second-g[j].second);
            if(dis[j] > d){
                dis[j] = d;
            }
            if(dis[j] < mn) { mn=dis[j], imn = j; }
        }
        swap(g[i+1],g[imn]);
        swap(dis[i+1],dis[imn]);
        sum+=mn;
    } cout << sum;

    return 0;
}