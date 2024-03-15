#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    int cnt=0;
    while(n--){
        int a,b; cin>>a>>b;
        if(a<=400 && b>=150 && b<=200) cnt++;
    } cout << cnt;

    return 0;
}