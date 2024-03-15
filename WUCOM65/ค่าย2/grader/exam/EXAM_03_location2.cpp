#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int g[2001][2001];
int qsv[2001][2001];
int qsh[2001][2001];
int qsrd[2001][2001];
int qsld[2001][2001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;
    memset(qsv,0,sizeof(qsv));
    memset(qsh,0,sizeof(qsh));
    memset(qsld,0,sizeof(qsld));
    memset(qsrd,0,sizeof(qsrd));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            qsv[i][j] = g[i][j]+qsv[i-1][j];
            qsh[i][j] = g[i][j]+qsh[i][j-1];
            qsld[i][j] = g[i][j]+qsld[i-1][j+1];
            qsrd[i][j] = g[i][j]+qsrd[i-1][j-1];
        }
    } 
    
    long long int sum=0;
    for(int j=1;j<=k;j++)
        sum+= qsv[k][j] - qsv[j-1][j]; 
    long long int summ=sum;
    long long int mx=-1e9;
    for(int i=k;i<=n;i++){
        if(i!=k){
            summ += qsh[i][k]-qsrd[i-1][k];
        } 
        sum=summ;
        mx=max(sum,mx);
        for(int j=k+1;j<=m;j++){
            sum+= qsrd[i][j]-qsrd[i-k][j-k]-qsv[i][j-k]+qsv[i-k][j-k];
            mx = max(sum,mx);
        } 
    } 

    sum=0;
    for(int j=m;j>=m-k+1;j--)
        sum+= qsv[k][j] - qsv[m-j][j]; 
    summ=sum;
    for(int i=k;i<=n;i++){
        if(i!=k){
            summ += qsh[i][m]-qsh[i][m-k]-qsld[i-1][m-k+1];
        } 
        sum=summ;
        mx=max(sum,mx);
        for(int j=m-1;j>=k;j--){
            sum+= qsld[i][j-k+1]-qsld[i-k][j+1] -qsv[i][j+1]+qsv[i-k][j+1];
            mx = max(sum,mx);
        }
    }
    cout << mx;
    return 0;
}