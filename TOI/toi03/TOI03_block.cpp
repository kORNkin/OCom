#include<bits/stdc++.h>
using namespace std;
int n,m,pnt=0,cnt=0;
char g[6][6];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool vis[6][6];
bool cheat(int x,int y,char op){
    int k=0;
    op=='L'?k=-1:k=1;
    if(x<0 || y<0 || x>=n || y>=m || g[x][y]=='-' || g[x][y]=='#' || y+k<0 || y+k>=m || g[x][y+k]!='-')
        return 1;
    return 0;
}
bool valid(int x,int y,char b){
    if(x<0 || y<0 || x>=n || y>=m || g[x][y]!=b)
        return 0;
    return !vis[x][y];
}
bool Fall(int &x,int &y,char b){
    bool ch=0;
    if(x+1>=0 && x+1<n && g[x+1][y]=='-'){
        g[x][y]='-';
        for(x;x<n-1;x++){
            if(g[x+1][y]!='-'){
                g[x][y]=b;
                break;
            }
        } ch=1;
    } return ch;
}

void DFS(int x,int y,char c){
    stack<pair<int,int>> st;
    st.push({x,y});
    bool ch=0;
    while(!st.empty()){
        pair<int,int> posi=st.top();
        st.pop();
        int a=posi.first,b=posi.second;
        if(ch){
            cnt++;
            g[a][b] = '-';
        }
        vis[a][b]=1;
        for(int i=0;i<4;i++){
            if(valid(a+dx[i],b+dy[i],c)){ 
                ch=1;
                st.push({a+dx[i],b+dy[i]});       
            }
        }
    }
    if(ch) g[x][y] = '-',cnt++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>g[i][j];
    
    int q;cin>>q;
    while(q--){
        int x,y; char op;
        cin>>x>>y>>op;
        if(cheat(x,y,op)){
            pnt-=5; continue;
        } 
        char b = g[x][y];
        g[x][y]='-';
        op=='L'?y--:y++;
        g[x][y]=b;
        Fall(x,y,b);
        memset(vis,0,sizeof(vis));
        cnt=0;
        DFS(x,y,b);
        pnt+= cnt*5;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]!='-' && g[i][j]!='#' ){
                    int tmpx=i,tmpy=j;
                    if(Fall(tmpx,tmpy,g[tmpx][tmpy])){
                        cnt=0;
                        DFS(tmpx,tmpy,g[tmpx][tmpy]);
                        pnt+= cnt*5;
                    }
                }
            }
        }
    }
    cout << pnt << '\n';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << g[i][j] << ' ';
        } cout << '\n';
    }
    return 0;
}