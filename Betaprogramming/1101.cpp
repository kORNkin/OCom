#include<bits/stdc++.h>
using namespace std;
#define st first 
#define nd second
string g[201][201];
int x=0,y=0,week=0,now=0,day=0;
pair<int,int> dir[]={{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,k,m;
    cin>>n>>k>>m;
    for(int i=0;i<200;i++)
        for(int j=0;j<200;j++)
            g[i][j] = "*";
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        cin>>g[a-1][b-1];
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << g[i][j];
        } cout << "\n";
    }*/
    bool ch=0;
    while(k){
        if(g[x][y] != "*" && !ch){
            char c = g[x][y][day%7];
            if(c!='S'){
                if(c=='R')
                    now++;
                else if(c=='L')
                    now--;
                k--;
                if(now==4) now=0;
                else if(now==-1) now=3;
                ch=1;
                continue;          
            }
        }
        if(x+dir[now].st<0 || x+dir[now].st>=n || y+dir[now].nd<0 || y+dir[now].nd>=n){
            now = (now+2)%4;
            k--;
            continue;   
        }
        x+=dir[now].st;
        y+=dir[now].nd;
        day++;
        ch=0;
        //out << "k: " << k << " day: " <<day << " : x_" << x << " y_"<< y << " now: " << now << "\n";
    } cout << day;
    

    return 0;
}
/*
1 0   --> 0 1
0 1   --> -1 0
-1 0  --> 0 -1
0 -1  --> 1 0 

    X
    |
----|----Y
    |
    |    
*/