#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    int dis[n],sum=0;
    for(auto &x:dis) {
        cin>>x; sum+=x;
    }
    cout << sum << "\n";
    int a=0,b=n-1;
    while(b!=a){
        if(dis[a]<dis[b]){
            sum-=dis[b];
            b--;
        }else {
            sum-=dis[a];
            a++;
        }   
        cout << sum << "\n";
    }
    cout << b+1;

    return 0;
}