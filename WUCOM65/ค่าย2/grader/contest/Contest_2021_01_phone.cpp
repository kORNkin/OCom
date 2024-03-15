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

    map<char,pair<int,int>> uph;
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            char c;cin>>c;
            uph[c]={i,j};
        }
    }
    string s; cin>>s;
    for(auto c:s)
        cout << ph[uph[c].first][uph[c].second];
    

    return 0;
}