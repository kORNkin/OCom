#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int n,k;
pair<int,int> cur[4];
int g[101][101];
bool isValid(int i,int dx,int dy)
{
    bool ch=1;
    for(int j=0;j<4;j++){
        if(j!=i && cur[j]== make_pair(dx,dy)){
            ch=0;
            break;
        }
    }
    if(ch && dx>=0 && dx<n && dy>=0 && dy<n){
        g[dx][dy]=i+1; return 1;
    }
    return 0; 
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>k;
    char move[k*4];
    for(int i=0;i<k*4;i++)
        cin>>move[i];
    memset(g,0,sizeof(g));
    cur[0] = {0,n-1};
    cur[1] = {n-1,n-1};
    cur[2] = {n-1,0};
    cur[3] = {0,0};
    g[0][n-1]=1;
    g[n-1][n-1]=2;
    g[n-1][0]=3;
    g[0][0]=4;
    vector<int> cnt(5,0);
    int mx=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<4;j++){
            if(move[k*j+i]=='N' && isValid(j,cur[j].x-1,cur[j].y))
                cur[j].x-=1;     
            else if(move[k*j+i]=='E' && isValid(j,cur[j].x,cur[j].y+1))
                cur[j].y+=1;
            else if(move[k*j+i]=='S' && isValid(j,cur[j].x+1,cur[j].y))
                cur[j].x+=1;
            else if(move[k*j+i]=='W' && isValid(j,cur[j].x,cur[j].y-1))
                cur[j].y-=1;
            /*for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout << g[i][j] << " ";
                }   cout << "\n";
            }
            cout << "\n";*/
        }
    }   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cnt[g[i][j]]++;
            mx=max(mx,cnt[g[i][j]]);
        }
    }
    if(cnt[0]){
        cout << "No\n";
        return 0;
    }
    vector<int> ans;
    for(int i=1;i<=4;i++){
        if(cnt[i]==mx)
            ans.push_back(i);
    }
    cout<<ans.size()<<" "<<mx<<"\n";
    for(auto e:ans) cout<<e<<"\n"; 
    return 0;
}
/*
3 2
S
E
W
W
N
N
E
S
*/