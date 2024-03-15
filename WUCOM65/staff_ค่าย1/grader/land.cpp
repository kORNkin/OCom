//land
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k;
    cin>>k;
    while(k--){
        int a,b,p,q,co=0;
        cin>>a>>b>>p>>q;
        for(int i=p; i<=q;i++){
            if(i*i > b) break;
            for(int j=i; j<=q;j++){
                if(i*j >= a && i*j <= b){
                    (i==j) ? co++ : co+=2;
                }else if(i*j > b) break;
            }
        }
        cout << co << "\n";
    }
    return 0;    
}