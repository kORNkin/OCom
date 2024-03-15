#include<bits/stdc++.h>
using namespace std;

long long dp[1001][1001];
const long long M = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n; cin >> n;

    dp[0][0] = 1;

    for(int i = 1; i <= 1000; i++) for(int j = 0; j <= i; j++) dp[i][j] = (!j | j==i? 1:dp[i - 1][j - 1] + dp[i - 1][j]) %M;

    while(n--){
        int a, b, c; cin >> a >> b >> c;
        if(a) cout << dp[b - 1][b - c] << '\n';
        else cout << dp[b + c - 1][b] << '\n'; 
    }   
    

	return 0;
}
