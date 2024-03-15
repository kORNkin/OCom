#include<bits/stdc++.h>
using namespace std;
struct Flower{
    int p,b,t;
};
int dp[1001][1001];
Flower arr[1001];

long long solve(int m,int i,int ln,int sh){
    if(m<0) return -1e9;
    if(i<0 || m==0){
        if((ln<=sh && (ln+1)*2 >= sh) || (ln>=sh && (sh+1)*2 >= ln)){
            return 0;
        }
        return -1e9;
    }
    if(dp[i][m]) return dp[i][m];

    if(arr[i].t == 1)
        return dp[i][m] = max(arr[i].b + solve(m-arr[i].p, i-1, ln+1,sh) , solve(m, i-1,ln,sh));
    else 
        return dp[i][m] = max(arr[i].b + solve(m-arr[i].p, i-1, ln,sh+1) , solve(m, i-1,ln,sh));
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

    int m,k;
    cin>>m>>k;

    memset(dp,0,sizeof(dp));

    for(int i=0;i<k;i++) cin>>arr[i].p>>arr[i].b>>arr[i].t;

    cout << solve(m,k-1,0,0);

    return 0;
}
/*
100 6 
40 1000 1 
20 100 1 
10 200 0
20 300 0
30 400 0
30 400 0

00100100100100 

*/