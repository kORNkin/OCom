#include<bits/stdc++.h>
using namespace std;
int n,m,k,l;
vector<long long> arr;
bool vis[1000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m>>k>>l;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        arr.push_back(x);
    }
    while(k--){
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++){
            int x; cin>>x;
            if(x-l > arr[n-1]) continue;
            int a = lower_bound(arr.begin(),arr.end(),x-l)-arr.begin();
            int b = lower_bound(arr.begin(),arr.end(),x+l)-arr.begin();
            if(arr[b] > x+l) b--;
            for(int j=a;j<=b;j++){
                vis[j] = 1;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]) cnt++;
        }
        cout << cnt << '\n'; 
    }

    return 0;
}