#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m;
    cin>>n>>m;
    int i,j,mx=0;
    int a,b,mn=1e9;
    while(m--){
        int x,y,w;
        cin>>x>>y>>w;
        if(mx<w){
            mx=w;
            i=x; j=y;
        }
        if(mn>w){
            mn=w;
            a=x; b=y;
        }
    }
    cout << fixed << setprecision(6) << (double)sqrt(pow(j-b,2)+pow(i-a,2));

    return 0;
}
