#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int a[N], f[N];

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

    int n; cin>>n;
    
    // Leetcode number of subarrays with sum k
    // Sliding window + prefix sum

    f[(N>>1)]=1; // or using unordered_map but slower a bit

    int ans=0, sum=0;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        sum += x;
        ans += f[sum + (N>>1)];
        f[sum + (N>>1)]++;
    } cout << ans;

    return 0;
}
