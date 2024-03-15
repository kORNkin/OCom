#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
vector<pair<ll,ll>> ans;
vector<pair<ll,ll>> v;
ll dp[251][251];

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first == b.first) 
        return a.second > b.second; 
    return a.first < b.first;

}

/*ll bin_search(ll l,ll r,ll x)
{
    ll m=(l+r)>>1;
    if(x<=ans[m].first){
        bin_search(0,m,x);
    }else bin_search(m,r,x);
}*/

void dfs(int cur,int k,ll dis)
{       
    if(cur==n-1){
        ans.push_back({dis,k});
        return;
    }
    for(int i=cur+1;i<n;i++){
        dis=max(dis,dp[cur][i]);
        dfs(i,k+1,dis);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int i,j;
    ll x,y,sum=0;
    cin>>n>>m;
    
    for(i=0;i<n;i++){
        cin>>x>>y;
        v.push_back({x,y});
        
    }
    /*for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            dp[i][j]=1e18;
            for(int k=i+1;k<=j;k++){
                dp[i][j] = min(dp[i][k]+dp[k][j],abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second));
                
            } cout << i << " to " << j << " :"<< dp[i][j] << "\n";
        }
    }*/
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            dp[i][j] = abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second);
            //cout << i << " to " << j << " :"<< dp[i][j] << "\n";
        }
        dp[i][i]=0;
    }
    for(i=1;i<n;i++){
        dfs(i,1,dp[0][i]);
    }
    sort(ans.begin(),ans.end(),cmp);
    /*for(auto e: ans)
        cout << e.first << " " << e.second << "\n";*/
    while(m--){
        cin>>x;
        //sum+=ans[bin_search(0,n-1,x)].second;
        if(x<dp[0][n-1]){
            for(i=0;i<ans.size();i++){
                if(x<ans[i].first){
                    sum+=ans[i-1].second;
                    break;
                }
            }
        }else sum+=1;
    }
    cout<<sum;

    return 0;
}
/*
5 2
0 1
2 2
3 6
6 6
9 10
10
15
*/
// มีปัญหาตรงไปทางจุดพักก่อนหน้ามีค่าน้อยกวา ไปจุดพักด้านหน้า
/*
5 2
0 0
2 0
7 0
4 0
10 0
10
3
*/