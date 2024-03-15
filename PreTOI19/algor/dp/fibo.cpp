#include<bits/stdc++.h>
using namespace std;
long long dp[10001];

long long fib(int n){
    if(n==1 || n==0) return dp[n]=1;
    if(dp[n]) return dp[n];

    return dp[n] = fib(n-1)+fib(n-2);
}

int main(){
    ios_base::sync_with_stdio(0);

    cout << fib(100);

    return 0;

}