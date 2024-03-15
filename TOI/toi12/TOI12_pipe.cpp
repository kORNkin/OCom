#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int n,k;
int dis[15001];
pair<int,int> g[15001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>g[i].f>>g[i].s, dis[i] = 1e9;
    
    vector<int> ans;
    for(int i=0;i<n;i++){
        int mn = 1e9, idx;
        for(int j=i+1;j<n;j++){
            int d = abs(g[i].f-g[j].f)+abs(g[i].s-g[j].s);
            if(dis[j] > d) dis[j] = d;
            if(mn > dis[j]){
                mn = dis[j]; idx = j;
            }
        }
        swap(g[i+1],g[idx]);
        swap(dis[i+1],dis[idx]);
        ans.push_back(mn); 
    } 
    sort(ans.begin(),ans.end());
    long long sum=0;
    for(int i=0;i<n-k;i++) sum+=ans[i];
    cout << sum;
    return 0;
}