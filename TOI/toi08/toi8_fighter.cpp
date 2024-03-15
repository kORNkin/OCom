#include<bits/stdc++.h>
using namespace std;
int p, e, o, se, so;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    cin >> p;
    e = o = p;
    for(int i = 0; i < p<<1; i++){
        int x; cin >> x;
        if(x&1){
            se = 0; so++; 
            if(so >= 3) e-=3;
            else e--;
        }else {
            so = 0; se++;
            if(se >= 3) o-=3;
            else o--;
        }
        if(e <= 0){
            cout << "1\n" << x;
            return 0;
        }else if(o <= 0){
            cout << "0\n" << x;
            return 0;
        }
    }

    return 0;
}