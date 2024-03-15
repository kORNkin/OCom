#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int w,h,n; cin>>w>>h>>n;
    int cnt[4001]; memset(cnt,0,sizeof(cnt));
    while(n--){
        int x,a; cin>>x>>a;
        for(int i=x;i<x+a;i++)
            cnt[i]++;
    }
    int one=0,half=0;
    for(int i=0;i<w;i++){
        if(cnt[i]==1) half++;
        else if(!cnt[i]) one++;
    } cout << one*h << ' ' << half*h;

    return 0;
}