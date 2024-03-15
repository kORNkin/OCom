#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a,b; cin>>a>>b;

    float co=0;
    for(int i=0;i<a.length();i++)
        if(a[i]==b[i]) co++;
    co = co/a.length() *100;
    if(co < 20) cout << "Aldebaran";
    else if(co<40) cout << "Norma";
    else if(co<60) cout << "Aquarius";
    else if(co<=100) cout << "Vela";

    return 0;
}