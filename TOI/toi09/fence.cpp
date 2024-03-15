#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T=2;
    while(T--){
        int n,m;
        cin>>m>>n;
        int t; cin>>t;
        int arr[m+5][n+5];
        memset(arr,0,sizeof(arr));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                arr[i][j]=1;
            }
        }
        while(t--){
            int x,y; cin>>x>>y;
            arr[x+1][y+1] = 0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                arr[i][j]+= arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
            }
        }
        int sq = min(m,n),cal,out,in;
        bool stop=false;
        for(int i=sq;i>0;i--){
            cal = i*i - (i-2)*(i-2);
            for(int j=i;j<=m;j++){
                for(int k=i;k<=n;k++){
                    out = arr[j][k]-arr[j-i][k]-arr[j][k-i]+arr[j-i][k-i];
                    in = arr[j-1][k-1]-arr[j-i+1][k-1]-arr[j-1][k-i+1]+arr[j-i+1][k-i+1];
                    if(cal == out - in){
                        cout << i  << '\n';
                        stop=1;
                        break;
                    } 
                }if(stop) break;
            }if(stop) break;
        } 
    }

    return 0;
}
/*
0 0 0 0 0 0 0 0 0
0 1 2 3 4 5 6 7 0
0 2 4 6 7 9 11 13 1
0 2 5 8 10 13 16 19 1
0 3 7 11 14 18 22 25 1
0 1 1 0 1 1 0 1 1
*/