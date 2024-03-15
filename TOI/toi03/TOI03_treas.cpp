#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin>>s;
    double x=0;
    double y=0;
    while(s!="*"){
        int i=0;
        double n=0;
        while(1){
            if(s[i]<'0' || s[i]>'9') break;
            n*=10;
            n+=s[i]-'0';
            i++;
        } i--;

        double m = n/sqrt(2);
        string op;
        while((++i)<s.size())
            op+=s[i];
        if(op=="N") y+=n;
        else if(op=="NE") x+=m,y+=m;
        else if(op=="E") x+=n;
        else if(op=="SE") x+=m,y-=m;
        else if(op=="S") y-=n;
        else if(op=="SW") y-=m,x-=m;
        else if(op=="W") x-=n;
        else x-=m,y+=m;

        cin>>s;
    }
    cout << fixed << setprecision(3) << x << " " << y << '\n' << sqrt(pow(x,2)+pow(y,2));
    
    return 0;
}