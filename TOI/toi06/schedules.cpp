#include<bits/stdc++.h>
using namespace std;

struct Time{
    int in,out,idx;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k,m,i; cin>>n>>k>>m;

    vector<Time> mem;
    
    for(i=0;i<n;i++){
        int a,b; cin>>a>>b;
        mem.push_back({a,b,i+1});
    }
    sort(mem.begin(),mem.end(),[&](Time a,Time b){
        return a.in < b.in;
    });

    bitset<500001> vis;
    priority_queue<int,vector<int>,greater<int>> now;
    
    for(i=0;i<k;i++) now.push(0);
    int nw;
    for(auto t:mem){
        nw=now.top();
        if(t.in <= nw) continue;
        vis[t.idx]=1;
        now.pop();
        now.push(t.out);
    }

    for(i=0;i<m;i++){
        int x; cin>>x;
        cout << (vis[x]?"Y ":"N ");
    }

    return 0;
}