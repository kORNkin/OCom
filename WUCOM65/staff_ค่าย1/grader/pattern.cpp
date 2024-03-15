#include <bits/stdc++.h>
using namespace std;
#define cin2(a) for(auto &x:a) for(auto &_x:x) cin>>_x;
#define memset(a,b) memset(a,b,sizeof(a))

bool num[101],vis[21][21];
int arr[21][21],ans[4];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
pair<int,int> patt[]= {{1,1},{1,-1},{-1,1},{-1,-1}};
int n,m;

bool valid(int x,int y,int &c){
    if(x>=0 && y>=0 && x<n && y<m && arr[x][y]==c)
        return 0;
    return !vis[x][y];
}
bool checkCorner(int x,int y,int &c,bool &cn)
{
    if(arr[x+1][y]==c && arr[x][y+1]==c) return 1;
    return 0;
}

int floodfill(int x,int y,int &c,int &cn)
{
    vector<pair<int,int>> ans;
    for(int i=0;i<4;i++){
        if(valid(x+dx[i],y+dy[i],c)){
            vis[x+dx[i]][y+dy[i]]=1;
            floodfill(x+dx[i],y+dy[i],c,cn);
            ans.push_back({x+dx[i],y+dy[i]});
        }
    }
    if(ans.size()==2){
        int x= ans[0].first+ans[1].first;
        int y= ans[0].second+ans[1].second;
        for(int i=0;i<4;i++){
            if(patt[i]==make_pair(x,y)) 
            {
                cn++;
                return i+1;
            }
        }
    }else if(ans.size()>2){
        num[c] = 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);

    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        cin2(arr);
        memset(ans,0);
        memset(vis,0);
        memset(num,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    int cn = 0;
                    floodfill(i,j,arr[i][j],cn);
                }
            }
        }

    }

    return 0;
}