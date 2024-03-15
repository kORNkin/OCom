#include <bits/stdc++.h>
using namespace std;
int n,k;
int arr[21];
bool ch=0;
void solve(int idx,int sum){
    if(ch) return;
    if(idx==n){
        if(sum<=0 || sum>k) return;
        if(k%sum == 0) ch=1;
        return;
    }
    solve(idx+1,sum+arr[idx]);
    solve(idx+1,sum-arr[idx]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ch=0;
        solve(0,0);

        if(ch) cout << "Y\n";
        else cout << "N\n";
    }

    return 0;
}
/*
3
3 2 1 2 3
4 6 5 1 2 4
3 9 1 2 3
*/