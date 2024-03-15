#include<bits/stdc++.h>
using namespace std;

int mod(string num,int m){
    int ans=0;
    for(int i=0;i<num.size();i++){
        ans = (ans*10 + num[i]-'0') %m;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b; cin>>n>>m>>a>>b;
    string num; cin>>num;

    cout << (b+mod(num,m))%m;

    return 0;
}
