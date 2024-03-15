#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while(T--){
        int l,r; cin>>l>>r;
        int cnt=0,mx=0;
        int n[10],x;
        bool ch;
        for(int i=l;i<=r;i++){
            memset(n,0,sizeof(n));
            x=i; 
            ch=0;
            while(x){
                n[x%10]++;
                if(n[x%10] > 1) {
                    ch=1;
                    break;
                }
                x/=10;
            }
            if(ch) cnt++;
            else {
                mx=max(mx,cnt);
                cnt=0;
            }

        }   
        cout << max(mx,cnt) <<'\n';
    }

    return 0;
}