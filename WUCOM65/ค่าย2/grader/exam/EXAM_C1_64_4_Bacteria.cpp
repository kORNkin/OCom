#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,cnt=0; cin>>n;
    for(int i=1;i<=n;i*=2)
        if(n&i) cnt++;
    cout << cnt;
    
    return 0;
}