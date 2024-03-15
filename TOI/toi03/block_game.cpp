#include<bits/stdc++.h>
using namespace std;
int n,m,score=0;
int curx,cury;
char board[5][5];
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};

bool DFS(int x,int y,char z)
{
    score+=5;
    board[x][y]='-';
    for(int i=0;i<4;i++){
        if(board[x+dx[i]][y+dy[i]]==z){
           DFS(x+dx[i],y+dy[i],z);
        }
    }
}
void scoreCheck(int x,int y,char z){
    for(int i=0;i<4;i++){
        if(board[x+dx[i]][y+dy[i]]==z){
           DFS(x+dx[i],y+dy[i],z);
        }
    }
}
void drop(int x,int  y){
    for(int i=n-1;i>x;i--){
        if(board[i][y]=='-'){
            board[i][y]=board[x][y];
            board[x][y]='-';
            curx = i;
            cury = y;
            break;
        }
    }
}
void blockGame(int x,int y)
{   
    curx = x; cury = y;
    drop(x,y);
    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << board[i][j] << " ";
        } cout << "\n";
    } 
    cout << curx << " " << cury << "\n";*/
    scoreCheck(curx,cury,board[curx][cury]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]!='-'&&board[i][j]!='#'&&board[i+1][j]=='-')
                blockGame(i,j);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>board[i][j];
    int k; cin>>k;
    for(int i=0;i<k;i++){
        int x,y,k;
        char z;
        cin>>x>>y>>z;
        if(z=='R') k=1;
        else k=-1;
        if(y+k>=0 && y+k<n && (board[x][y+k]!='-' || board[x][y]=='#' || board[x][y]=='-')){
            score-=5;
            continue;
        }
        board[x][y+k]=board[x][y];
        board[x][y]='-';
        blockGame(x,y+k);
    } cout << score << "\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << board[i][j] << " ";
        } cout << "\n";
    }

    return 0;
}
/*
5 5
# A - B #
# B - A #
# # - B #
# A B # #
# # # # #
3
0 1 L
0 3 L
0 1 R
*/