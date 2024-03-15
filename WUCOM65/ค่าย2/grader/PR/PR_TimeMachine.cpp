#include <bits/stdc++.h>
using namespace std;
struct TimeMachine{
    int x,y,p;
};
int n,m,k,mn=1e9;
TimeMachine arr[10001];
bool vis[10001];
void solve(int curx,int cury,int sumt, string ans){
    int dis = ceil(sqrt(pow(n-1-curx,2)+pow(m-1-cury,2)));
    mn = min(mn,sumt+dis);
    for(int i=0;i<k;i++){
        if(!vis[i]){
            vis[i]=1;
            dis = ceil(sqrt(pow(curx-arr[i].x,2)+pow(cury-arr[i].y,2)));
            ans.push_back(i+'0');
            solve(arr[i].x,arr[i].y,sumt+dis-arr[i].p,ans);
            ans.pop_back();

            vis[i]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
        cin>>arr[i].x>>arr[i].y>>arr[i].p;

    memset(vis,0,sizeof(vis));
    solve(0,0,0,"");

    cout << mn;

    return 0;
}