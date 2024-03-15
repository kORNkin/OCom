#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string a,b;
    cin>>a>>b;
    int n=a.length(),cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]) cnt++;
    }   
    string arr[]={"Aldebaran","Norma","Aquarius","Vela"};
    int rate[]={20,40,60,101};
    double x = cnt* 100 /n;
    //cout << x << "\n";
    for(int i=0;i<4;i++){
        if(x<rate[i]){
            cout << arr[i];
            return 0;
        }
    }

    return 0;
}