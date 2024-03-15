#include <bits/stdc++.h>
#include <windows.h>
#include <mem.h>
using namespace std;
int N=4;
int g[10001];
bool row[10001];
bool yx[10001];
bool xy[10001];
void show(){
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            if(g[x]==y)
                cout << 'Q';
            else cout << '.';
        }cout <<'\n';
    } cout << '\n';
    Sleep(100);
    system("cls");
}

void solve(int x){
    if(x==N) show();
    else {
        for(int y=0;y<N;y++){
            if(row[y] || yx[x+y] || xy[x-y+N]) continue;
            row[y]=1;
            yx[x+y]=1;
            xy[x-y+N]=1;
            g[x]=y;
            solve(x+1);
            row[y]=0;
            yx[x+y]=0;
            xy[x-y+N]=0;
        }
    }
}
int main()
{
    memset(row,0,sizeof(row));
    memset(yx,0,sizeof(yx));
    solve(0);

    return 0;
}