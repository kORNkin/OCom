#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k,m,i,j,l; cin>>k>>m;
    vector<string> st(k);
    for(auto &x:st) cin>>x;
    int t; cin>>t;
    while(t--){
        int n; 
        string t;
        cin>>n>>t;
        bool ch[k],fg,vd=1;
        memset(ch,0,sizeof(ch));
        for(i=0;i<k;i++){
            for(j=0;j<t.size();j++){
              if(st[i][0] == t[j]){
                fg=1;
                for(l=1;l<m;l++){
                    if(st[i][l] != t[j+l]){
                        fg=0;
                        break;
                    }
                }
                if(fg) {
                    ch[i]=1;
                    vd=0;
                    cout << i+1 << " ";
                    break;
                }
              }  
            }
        } 
        if(vd) cout<< "OK";
        cout<<'\n';
    }

    return 0;
}
/*
5 6 
000111 
111000 
110011 
100110 
001100 
1
16 
1011101001110011
*/