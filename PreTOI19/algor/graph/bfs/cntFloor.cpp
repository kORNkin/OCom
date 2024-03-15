#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int T; cin>>T;
	while(T--){
		int n,m; cin>>n>>m;
		vector<int> g[n+1];
		for(int i=1;i<=m;i++){
			int u,v; cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		//BFS
		bool vis[n+1];
		memset(vis,0,sizeof(vis));
		int dis[n+1];
		queue<int> q;
		q.push(1);
		vis[1] = 1;
		dis[1] = 0;

		bool ch=0;
		while(!q.empty()){
			int x = q.front();
			q.pop();
			
			for(auto e:g[x]){
				if(!vis[e]){
					vis[e]=1;
					q.push(e);
					dis[e] = dis[x]+1;
					if(e==n) ch=1;
				}
				if(ch) break;
			}
			if(ch) break;
		}
		cout << dis[n] << '\n';

	}
	return 0;
}