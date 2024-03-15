#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,mx=0; cin>>n;
    int co[10001];
    set<int> num;
    memset(co,0,sizeof(co));
    for(int i=0;i<n;i++){
        int x;cin>>x;
        num.insert(x);
        co[x]++;
        mx=max(mx,co[x]);
    }
    for(auto x:num){
        if(mx==co[x]){
            cout << x << " ";
        }
    }

    return 0;
}