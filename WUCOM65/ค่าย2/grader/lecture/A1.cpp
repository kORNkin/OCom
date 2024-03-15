#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#define mod 1000000007
int n,m;
char g[1001][1001];
long long dp[1001][1001];
int dx[]={1,0};
int dy[]={0,1};
bool valid(int xx,int yy){
    if(xx >=0 && yy >=0 && xx<n && yy<m)
        return 1;
    return 0;
}
long long cnt=0;
long long flood(int x,int y){
    if(dp[x][y] != 0) return dp[x][y]%mod;
    for(int i=0;i<2;i++){
        int xx=x+dx[i], yy=y+dy[i];
        if(valid(xx,yy)){
            while(valid(xx,yy) && g[xx][yy]== '1'){
                xx+=dx[i];
                yy+=dy[i];
            }
            if(dp[xx][yy]!=0) dp[x][y] +=dp[xx][yy]%mod;
            else dp[x][y] += flood(xx,yy);
        }
    }
    return dp[x][y]%mod;
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    scanf("%d %d",&n,&m);
    char c=getchar();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //scanf("%c", &g[i][j]);
            g[i][j] = getchar();
            dp[i][j]=0;
        } c=getchar();
    }

    dp[n-1][m-1] = 1;
    printf("%ld",flood(0,0)); 

    return 0;
}
/*
3 3
010
100
000

4 4
0000
0110
0110
0000
*/