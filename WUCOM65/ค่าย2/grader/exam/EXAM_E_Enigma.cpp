#include<bits/stdc++.h>
using namespace std;
int port[2][4] = {0,3,1,2 , 0,2,1,3};
int rev[2][4] = {0,2,3,1 , 0,2,1,3};
int k=0;
void solve(){
    k++;
    int tmp[]={port[0][0],rev[0][0],port[1][0],rev[1][0]};
    for(int j=0;j<4;j++){
        if(j!=3) {
            port[0][j] = (port[0][j+1]-1 != -1)? port[0][j+1]-1:3;
            rev[0][j] = (rev[0][j+1]-1 != -1)? rev[0][j+1]-1:3;
        }
        else 
        {
            port[0][j] = (tmp[0]-1 != -1)?tmp[0]-1:3;
            rev[0][j] = (tmp[1]-1 != -1)?tmp[1]-1:3;
        }

        if(k%4==0){
            if(j!=3) {
                port[1][j] = (port[1][j+1]-1 != -1)? port[1][j+1]-1:3;
                rev[1][j] = (rev[1][j+1]-1 != -1)? rev[1][j+1]-1:3;
            }
            else 
            {
                port[1][j] = (tmp[2]-1 != -1)?tmp[2]-1:3;
                rev[1][j] = (tmp[3]-1 != -1)?tmp[3]-1:3;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    int m,n; cin>>m>>n>>s;
    string ans = "ABCD";

    while(m--)
        solve();
    int tmp1 = port[1][port[0][s[0]-'A']];
    cout << ans[rev[0][rev[1][abs(tmp1-3)]]];
    for(int i=1;i<s.size();i++){
        solve();
        
        /*cout << "-------------" << k << "-------------\n";
        for(int j=0;j<4;j++){
            cout << ans[j] << " " << port[0][j] << '\n';
        } cout << '\n';
        for(int j=0;j<4;j++){
            cout << ans[j] << " " << port[1][j] << '\n';
        }*/
        
        tmp1 = port[1][port[0][s[i]-'A']];
        cout << ans[rev[0][rev[1][abs(tmp1-3)]]];
    }

    return 0;
}