#include<bits/stdc++.h>
using namespace std;
bool palin(string s){
    string rev=s; 
    reverse(s.begin(),s.end());
    return rev == s;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin>>m>>n;
    char arr[n][m];
    for(auto &x:arr) for(auto &xx:x) cin>>xx;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            string h;
            for(int k=0;k<m;k++)
                h.push_back(arr[i][k]);
            string v;
            for(int k=0;k<n;k++)
                v.push_back(arr[k][j]);
            bool a = palin(v), b = palin(h);
            if(a&&b) cout << 'B';
            else if(a) cout << 'V';
            else if(b) cout << 'H';
            else cout << 'N';
        } cout << '\n';
    }

    
    return 0;
}