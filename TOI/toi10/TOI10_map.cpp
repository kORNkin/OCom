#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int arr[1001][1001];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int m,n; cin>>m>>n;
    
    vector<pair<int,char>> g[m*n];
    for(int i=0;i<m*n-1;i++){
        int x,y; char c;
        cin>>x>>c>>y;
        if(c=='U'){
            g[x].push_back({y,c});
            g[y].push_back({x,'S'});
        }else {
            g[x].push_back({y,c});
            g[y].push_back({x,'R'});
        }
    }
    queue<pair<int,pair<int,int>>> q;
    vector<bool> vis(m*n,0);
    int mnx=1e9, mny=1e9;
    q.push({0,{500,500}});
    while(!q.empty()){
        int idx = q.front().f;
        int x = q.front().s.f;
        int y = q.front().s.s;
        q.pop();
        
        if(vis[idx]) continue;
        vis[idx]=1;
        mnx = min(mnx,x);
        mny = min(mny,y);
        arr[x][y] = idx+1;
        for(auto e:g[idx]){
            if(e.s == 'U'){
                q.push({e.f,{x+1,y}});
            }else if(e.s == 'S'){
                q.push({e.f,{x-1,y}});
            }
            else if(e.s == 'L'){
                q.push({e.f,{x,y+1}});
            }
            else if(e.s == 'R'){
                q.push({e.f,{x,y-1}});
            }
        }
    }
    int cnt=0;
    for(int i=mnx;i<1000;i++){
        for(int j=mny;j<1000;j++){
            if(arr[i][j]) cout << arr[i][j]-1 << ' ', cnt++;
        } if(cnt && cnt%n==0) cout << '\n';
        if(cnt >= m*n) return 0;
    }

    return 0;
}