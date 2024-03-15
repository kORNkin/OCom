#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pair<int,int> posi[]={{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
    string num[3][3]={"","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
    int n; cin>>n; n--;
    string ans;
    int m,k; cin>>m>>k;
    int x=posi[m-1].first, y=posi[m-1].second;
    if(x!=0 || y!=0) ans.push_back(num[x][y][(k-1)%num[x][y].size()]);
    while(n--){
        int kx,ky; cin>>ky>>kx>>k;
        x+=kx; y+=ky;
        if(x==0 && y==0) 
            while(!ans.empty() && k--) ans.pop_back();
        else ans.push_back(num[x][y][(k-1)%num[x][y].size()]);
    }
    if(ans.size())
        cout << ans;
    else cout << "null";

    return 0;
}