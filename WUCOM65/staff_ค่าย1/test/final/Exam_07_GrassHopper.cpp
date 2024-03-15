#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
vector<pair<int,int>> g;
bool ch[1001][1001];
int r,c;
bool valid(int x,int y){
    if(x>=1 && x<=r && y>=1 && y<=c)
        return ch[x][y];
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
   
    memset(ch,0,sizeof(ch));
    cin>>r>>c;   
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        ch[x][y]=1;
        g.push_back({x,y});
    }
    int mx=0,cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cnt=0;
            int x,y,a,b;
            x=g[j].F-g[i].F;
            y=g[j].S-g[i].S;
            a=g[i].F;
            b=g[i].S;
            //cout << a << " " << b << ":";
            while(valid(a,b)){
                a+=x; b+=y;
                cnt++;
                //cout << a << " " << b << ":";
            }
            //cout << endl;
            if(cnt>=3) mx=max(mx,cnt);
        }
        //mx=max(mx,cnt);
    }
    cout << mx;

    return 0;
}
