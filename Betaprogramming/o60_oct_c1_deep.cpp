#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
vector<int> g[200001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        if(a!=-1) g[i].push_back(a); 
        if(b!=-1) g[i].push_back(b);
    }

    while(m--){
        int l,s,a,b; cin>>l>>s>>a>>b;
        stack<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int idx = q.top().first , deep = q.top().second;
            q.pop();

            int dir = 0;
            if(g[idx].size() > 1){
                dir = ((s&8) >> 3);
                s = (s * a + b ) % 40507;
            }
            if(deep+1 == l || !g[g[idx][dir]].size()) {
                cout << g[idx][dir] << '\n';
                break;
            }
            else q.push({g[idx][dir],deep+1});
        }
    }

    return 0;
}