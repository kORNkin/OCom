#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a,b; cin>>a>>b;
    if(a>20 || (a==20 && b>=45)) {
        cout << "0 0";
        return 0;
    }
    b = (20*60+45) - (a*60)-b;
    cout << b << " " << ceil(b/2.0);

    return 0;
}