#include<bits/stdc++.h>
#include<windows.h>
#include<mem.h>
using namespace std;
int N = 42;
bool cell[10001][10001];
int cnt[10001][10001];
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};
void show(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(cell[i][j]) cout << 'O';
            else cout << '-';
        } cout << '\n';
    }
    Sleep(100);
    system("cls");
}

void game(pair<int,int> start[],int size)
{
    for(int i=0;i<size;i++){
        int x = start[i].first;
        int y = start[i].second; 
        cell[x][y] = 1;
        for(int j=0;j<8;j++){
            cnt[x+dx[j]][y+dy[j]]++;
        }
    }
    /*for(int x=1;x<=N;x+=2){
        for(int y=1;y<=N;y++){
            cell[x][y] = 1;
            for(int j=0;j<8;j++){
                cnt[x+dx[j]][y+dy[j]]++;
            }
        }
    }*/
    while(1){
        show();
        vector<pair<int,int>> die;
        vector<pair<int,int>> born;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(cell[i][j] && (cnt[i][j]<2||cnt[i][j]>3))
                    die.push_back({i,j});
                if(cnt[i][j]==3 && !cell[i][j])
                    born.push_back({i,j});
            }
        }
        for(auto x:die){
            int i=x.first;
            int j=x.second;
            cell[i][j] = 0;
            for(int k=0;k<8;k++)
                cnt[i+dx[k]][j+dy[k]]--;            
        }
        for(auto x:born){
            int i=x.first;
            int j=x.second;
            cell[i][j] = 1;
            for(int k=0;k<8;k++)
                cnt[i+dx[k]][j+dy[k]]++;
        }
    }
}

int main()
{
    memset(cell,0,sizeof(cell));
    memset(cnt,0,sizeof(cnt));

    pair<int,int> start[] = {{4,3},{4,4},{4,5},{3,5},{2,4}};
    int n = sizeof(start)/sizeof(start[0]);
    game(start,n);

    return 0;
}