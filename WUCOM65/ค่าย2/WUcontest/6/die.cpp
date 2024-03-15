#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

char g[14][14];
int l=3,r=4,m=1,n=2,s=5,nn=6;
int op[7]= {0,6,5,4,3,2,1}; 
int x=7,y=7;
char posi='N';
void Change(){
    if(posi=='N'){
        n=m; m=s; nn=op[m]; s=op[n];
    }else if(posi=='S'){
        s=m; m=n; n=op[s]; nn=op[m];
    }else if(posi=='E'){
        r=m; m=l; l=op[r]; nn=op[m];
    }else if(posi=='W'){
        l=m; m=r; r=op[l]; nn=op[m];
    }
}

void Go(){
    if(posi=='N'){
        x--;
        if(x<=1) x=12;
    }else if(posi=='S'){
        x++;
        if(x>=13) x=2;
    }else if(posi=='W'){
        y--;
        if(y<=1) y=12;
    }else if(posi=='E'){
        y++;
        if(y>=13) y=2;
    }
    Change();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for(int i=1;i<=13;i++){
        for(int j=1;j<=13;j++){
            if(i==1 || i==13 || j==1 || j==13) g[i][j]='x';
            else g[i][j] = '1';
        }
    }
    for(int i=6;i<=8;i++){
        for(int j=6;j<=8;j++){
            cin>>g[i][j];
        }
    }

    long long k; cin>>k;
    while(k--){
        int sum = (g[x][y]-'0')+m;
        if(sum>6) sum-=6;
        g[x][y] = char(sum+'0');

        if(sum==2){
            if(posi=='N') posi='E';
            else if(posi=='S') posi='W';
            else if(posi=='E') posi='S';
            else if(posi=='W') posi='N';
        }else if(sum==3 || sum==4){
            if(posi=='N') posi='S';
            else if(posi=='S') posi='N';
            else if(posi=='E') posi='W';
            else if(posi=='W') posi='E';
        }else if(sum==5){
            if(posi=='N') posi='W';
            else if(posi=='S') posi='E';
            else if(posi=='E') posi='N';
            else if(posi=='W') posi='S';
        } Go();
    }
    for(int i=x-1;i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            cout << g[i][j];
        } cout << '\n';
    }

    return 0;
}
/*
//N
n=m; m=s; nn=op[m]; s=op[n];

//S
s=m; m=n; n=op[s]; nn=op[m];

//E
r=m; m=l; l=op[r]; nn=op[m];

//W
l=m; m=r; r=op[l]; nn=op[m];
*/

/*
x x x x x x x x x x x x x 
x 1 1 1 1 1 1 1 1 1 1 1 x 
x 1 1 1 1 1 1 1 1 1 1 1 x 
x 1 1 1 1 1 1 1 1 1 1 1 x 
x 1 1 1 1 1 1 1 1 1 1 1 x 
x 1 1 1 1 1 3 5 1 1 1 1 x 
x 1 1 1 1 1 6 5 1 1 1 1 x 
x 1 1 1 1 1 1 5 1 1 1 1 x 
x 1 1 1 1 1 1 1 1 1 1 1 x 
x 1 1 1 1 1 1 1 1 1 1 1 x 
x 1 1 1 1 1 1 1 1 1 1 1 x 
x 1 1 1 1 1 1 1 1 1 1 1 x 
x x x x x x x x x x x x x
*/