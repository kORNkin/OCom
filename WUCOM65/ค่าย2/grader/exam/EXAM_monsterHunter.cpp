#include <bits/stdc++.h>
using namespace std;
int n;
int col[21];
bool xy[21],yx[21],row[21];
int arr[21][21];

int mx=0;
void solve(int i,int sum){
    if(i == n){
        mx = max(mx,sum);
        return;
    }
    for(int j=0;j<n;j++){
        if(row[j] || xy[i+j] || yx[i-j+n]) continue;
        row[j]=1;
        xy[i+j]=1;
        yx[i-j+n]=1;
        col[i]=j;
        solve(i+1,sum+arr[i][j]);
        row[j]=0;
        xy[i+j]=0;
        yx[i-j+n]=0;

    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    memset(row,0,sizeof(row));
    memset(xy,0,sizeof(xy));
    memset(yx,0,sizeof(yx));
    
    solve(0,0);

    cout << mx;
    return 0;
}