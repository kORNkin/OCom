#include<bits/stdc++.h>
using namespace std;
#define f first 
#define s second 
int n,m; 
int dng[200001];
int vis[200001];
bool found;
void solve(int i,vector<pair<int,int>> &gem){ 
    if(found) return;
    if(i>=n){
        found = 1;
        return;
    }
    if(!vis[dng[gem[i].f]]){
        vis[gem[i].f]++;
        solve(i+1,gem);
        vis[gem[i].f]--;
    }
    if(!vis[dng[gem[i].s]]){
        vis[gem[i].s]++;
        solve(i+1,gem);
        vis[gem[i].s]--;
    } 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T=5;
    while(T--){
        found = 0;

        cin>>n>>m;
        vector<pair<int,int>> gem(n);
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)   
            cin>>gem[i].f>>gem[i].s;
        for(int i=0;i<m/2;i++){
            int a,b; cin>>a>>b;
            dng[a]=b;
            dng[b]=a;
        }   
        solve(0,gem);
        if(found) cout << 'Y';
        else cout << 'N';
    }

    return 0;
}