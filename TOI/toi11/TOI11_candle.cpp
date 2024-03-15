#include<bits/stdc++.h>
using namespace std;
char g[2001][2001];
bool vis[2001][2001];
int n,m;
int dx[] = {1,1,-1,-1,0,0,1,-1};
int dy[] = {1,-1,1,-1,1,-1,0,0};

void DFS(int i,int j){
    vis[i][j]=1;

    stack<pair<int,int>> st;
    st.push({i,j});
    while(!st.empty()){
        pair<int,int> t = st.top();
        st.pop();

        for(int i=0;i<8;i++){
            int x=t.first + dx[i], y=t.second + dy[i];
            if(x>=0 && y>=0 && x<n && y<m && g[x][y] == '1' && !vis[x][y]){
                st.push({x,y});
                vis[x][y]=1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> g[i][j]; 

    int cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='1' && !vis[i][j]){
                DFS(i,j);
                cnt++;
            }
        }
    } cout << cnt;
    
    return 0;
}