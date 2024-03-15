#include<bits/stdc++.h>
using namespace std;
char op[]={'q','w','e','a','d','z','x','c'};
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    char ph[4][3]={'1','2','3',
                   '4','5','6',
                   '7','8','9',
                   '*','0','#'};

    string s; cin>>s;
    int x=-1,y;
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(s[0]==ph[i][j]){
                x=i; y=j;
                break;
            }
        }if(x!=-1) break;
    } cout << s[0];
    for(int i=1;i<s.size();i++){
        for(int j=0;j<8;j++){
            if(s[i]==op[j]){
                x+=dx[j]; y+=dy[j];
                cout << ph[x][y];
                break;
            }
        }
    }

    return 0;
}