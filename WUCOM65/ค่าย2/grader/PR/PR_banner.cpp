#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    char c; cin>>c;
    int n,w,x; cin>>n>>w>>x;
    int m=2*n+1,k=0;
    for(int ii=0;ii<m*(x+1);ii++){
        for(int jj=0;jj<w;jj++){
            int i = ii%m;
            int j = (jj+m-ii/m)%m;
            if(i-n<=j && i+n >= j && i+j>=n  && i+j<=3*n) cout << c;
            else cout << '.';
        } cout << '\n';
    }
    
    

    return 0;
}