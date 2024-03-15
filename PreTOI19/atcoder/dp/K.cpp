#include<bits/stdc++.h>
using namespace std;

int n, k, arr[101], dp[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            if(i >= arr[j] && !dp[i - arr[j]]){
                dp[i] = 1;
                break;
            }
        }
    }

    cout << (dp[k]? "First": "Second");

    return 0;
}
