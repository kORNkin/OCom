#include<bits/stdc++.h>
using namespace std;
bool isPrime[10001] = {0};
vector<int> prime;
vector<int> g[10001];
void PrimeCal(){
    for(int i=4;i<10001;i+=2) isPrime[i]=1;
    for(int i=3;i<10001;i+=2){
        if(!isPrime[i]){
            for(int j=i*i;j<10001;j+=i)
                isPrime[j]=1;
            if(i>1000) prime.push_back(i);
        }
    }
}
void GraphSpawn(int a,int b){
    int cnt=0;
    int x=a,y=b;
    while(x>0){
        if(x%10 != y%10) cnt++;
        x/=10; y/=10;
    }
    if(cnt==1){
        g[a].push_back(b);
        g[b].push_back(a);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    PrimeCal(); 
    for(int i=0;i<prime.size();i++)
        for(int j=i+1;j<prime.size();j++)
            GraphSpawn(prime[i],prime[j]);

    while(T--){
        int a,b; cin>>a>>b;

        bool vis[10001];
        int dis[10001];
        for(int i=1000;i<=9999;i++) 
            dis[i]=-1, vis[i]=0; 

        //BFS
        queue<int> q;
        q.push(a);
        dis[a]=0;
        vis[a]=1;

        bool ch=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();

            for(auto e:g[x]){
                if(!vis[e]){
                    vis[e]=1;
                    q.push(e);

                    dis[e] = dis[x]+1;

                    if(e==b) ch=1;
                }
                if(ch) break;
            }
            if(ch) break;
        }
        if(dis[b] == -1) cout << "Impossible\n";
        else cout << dis[b] << '\n';
    }    

    return 0;
}