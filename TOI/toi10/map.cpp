#include<bits/stdc++.h>
using namespace std;

struct Point{
    char di;
    int n;
};
struct Point2{
    int n;
    int x;
    int y;
    int pr;
};

int ans[201][201];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m,n; cin>>m>>n;
    vector<Point> p[m*n];
    for(int i=0;i<m*n-1;i++){
        int a,b;
        char c;
        cin>>a>>c>>b;
        if(c=='U'){
            p[b].push_back({'u',a});
            p[a].push_back({'s',b});
        }else {
            p[b].push_back({'l',a});
            p[a].push_back({'r',b});
        }
    }
    Point2 mem[m*n];
    mem[0] = {0,0,0,-1};
    bool vis[m*n];
    memset(vis,0,sizeof(vis));

    int x,y,mn_x=1e9, mn_y=1e9;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int i=q.front();
        q.pop();
        if(vis[i]) 
            continue;
        vis[i]=1;
        x=mem[i].x;
        y=mem[i].y;
        for(Point e:p[i]){
            if(vis[e.n]) 
                continue;
            if(e.di == 'u'){
                mem[e.n].x = x-1;
                mem[e.n].y = y;
            }else if(e.di == 's'){
                mem[e.n].x = x+1;
                mem[e.n].y = y;
            }else if(e.di == 'l'){
                mem[e.n].x = x;
                mem[e.n].y = y-1;    
            }else {
                mem[e.n].x = x;
                mem[e.n].y = y+1;
            }
            mn_x = min(mn_x,mem[e.n].x);
            mn_y = min(mn_y,mem[e.n].y);
            mem[e.n].pr = i;
            q.push(e.n);
        }
    }
    x = 0-mn_x; y = 0-mn_y;
    for(int i=0;i<m*n;i++){
        ans[mem[i].x+x][mem[i].y+y] = i;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << ans[i][j] << " ";
        } cout << '\n';
    }

    return 0;
}
/*
2 3
1 L 2
2 U 0
3 U 5
0 L 5
4 L 0
*/