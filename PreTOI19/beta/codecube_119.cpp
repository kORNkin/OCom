#include<bits/stdc++.h>
using namespace std;

int n, m, k, x;
int dp[2][10001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < m; i++) cin >> dp[0][i];

    deque<int> q;
    int mx[m];
    for(int i = 1; i < n; i++){
        
        q.clear();
        memset(mx, 0, sizeof(mx));
        for(int j = 0; j < k; j++){
            while(!q.empty() && dp[~i&1][j] > dp[~i&1][q.back()])
                q.pop_back();
            q.push_back(j);
        } 
        for(int j = k; j < m; j++){
            while(!q.empty() && dp[~i&1][j] > dp[~i&1][q.back()])
                q.pop_back();
            while(!q.empty() && j - q.front() > k)
                q.pop_front();
            q.push_back(j);
            mx[j - k] = dp[~i&1][q.front()];
        }       
        
        for(int j = 0; j < m; j++){
            cin >> dp[i&1][j];
            dp[i&1][j] += max(mx[min(j, m - k - 1)], mx[max(j - k, 0)]);
        } 
    }
    mx[0] = 0;
    for(int i = 0; i < m; i++) mx[0] = max(mx[0], dp[(n-1)&1][i]);
    cout << mx[0];

    return 0;
}