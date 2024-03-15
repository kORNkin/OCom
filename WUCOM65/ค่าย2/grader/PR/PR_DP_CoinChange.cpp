#include<bits/stdc++.h>
using namespace std;
int dp[301];
int n,k,cnt;
int solve(int i, int ans, int arr[]){
    if(ans > k || i >= n) return;
    if(ans==k) {
        cnt++; 
        return;
    }

    solve(i,ans + arr[i], arr);
    solve(i+1,ans ,arr);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

    int T; cin>>T;
    while(T--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        //sort(arr,arr+n);
        cin>>k;

        cnt = 0;
        solve(0,0,arr);
        cout << cnt << '\n';
    }

	return 0;
}
/*
1
3 
1 2 3
4

2
3
1 2 3
4
4
2 5 3 6
10
*/