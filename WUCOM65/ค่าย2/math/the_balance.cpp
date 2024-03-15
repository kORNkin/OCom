#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        bool neg=0;
        if(n<0) n*=-1,neg=1;
        int r[100],idx=0;
        while(n){
            if(n%3==2){
                n++;
                r[idx] = -1;
            }
            else r[idx] = n%3;
            n/=3;
            idx++;
        }
        for(int i=idx-1; i>=0; i--){
            if(neg) cout << r[i]*-1 << ' ';
            else cout << r[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}