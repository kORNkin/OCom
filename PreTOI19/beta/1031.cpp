#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k,n,m;
    cin>>k>>n>>m;
    vector<int> tower[n+1];
    while(m--){
        int x,y;
        cin>>x>>y;
        tower[x].push_back(y);
    }
    
    int dis[n+1];
    for(int i=1;i<=n;i++) dis[i]=1e9;
    dis[1]=0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int f=q.front();
        q.pop();

        for(auto e:tower[f]){
            if(dis[e]>dis[f]+1){
                dis[e] = dis[f]+1;
                q.push(e);
            }
        }
    }
    for(int i=n;i>=1;i--)
    {
        if(dis[i] <= k){
            cout << i;
            break;
        }
    }

    return 0;
}
/*
3 6 5
1 2
1 3
2 5
3 4
5 6
*/