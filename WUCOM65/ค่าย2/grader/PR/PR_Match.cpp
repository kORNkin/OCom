#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin>>T;
    while(T--){
        int n=0; 
        string m; cin>>m;
        int arr[]={6,2,5,5,4,5,6,3,7,6};
        for(int i=0;i<m.size();i++)
            n+=arr[m[i]-'0'];
        string ans;
        if(n%2==0) 
            while(n) ans+='1',n-=2;
        else {
            n-=3;
            ans+='7';
            while(n) ans+='1',n-=2;
        }
        cout << ans << '\n';
    }

    return 0;
}